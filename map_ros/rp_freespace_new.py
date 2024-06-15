#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
import smach
import sys
import roslib
import math
import numpy as np
import actionlib
from scipy.spatial import distance
import yaml

from hsrlib.hsrif import HSRInterfaces
from hsrlib.utils import description, locations, joints
from hsrlib.rosif import ROSInterfaces
#from hsrnavlib import LibHSRNavigation
from tamlib.tf import Transform, euler2quaternion, transform_pose

# from tam_mmaction2.msg import Ax3DPoseWithLabelArray, AxKeyPoint
from geometry_msgs.msg import Point, Pose, Pose2D, Quaternion
from csra_pkg.msg import GetAttrAction, GetAttrGoal, GetAttrResult
from visualization_msgs.msg import Marker
from sensor_msgs.msg import Image, LaserScan, CameraInfo
from tamlib.utils import Logger
from GP_RP_PARAM import *
from human_position.msg import HumanCoordinatesArray, Keypoint


sys.path.append(roslib.packages.get_pkg_dir("hma_env_manage") + "/script")
from lib_manage_env import libManageEnv

from hma_env_manage.srv import (
    GetAreaService,
    GetAreaServiceRequest
)

class TellFreeSpace(smach.State, Logger):
    def __init__(self, outcomes):
        smach.State.__init__(self, outcomes=outcomes)
        Logger.__init__(self)
        
        self.hsrif = HSRInterfaces()
        self.rosif = ROSInterfaces()
        #self.nav = LibHSRNavigation()
        self.lme = libManageEnv()
        self.tamtf = Transform()
        self.description = description.load_robot_description()
        
        self.action_client = actionlib.SimpleActionClient('attribute_server', GetAttrAction)
        self.action_client.wait_for_server()
        # self.pub_register("marker_area", "~area", Marker)
        # self.human_point_pub = rospy.Publisher("human_point", Marker, queue_size=1)
        
        # judge inside or outside of arena
        self.srv_search_room = rospy.ServiceProxy(
            "env_search/get_room", GetAreaService
        )
        rospy.wait_for_service("env_search/get_room", timeout=10)
        
        self.not_done_suggest = True
        self.not_done_feature = True #これinitで宣言する必要ないね．変えてもらって大丈夫です．
        
        rp_param_path = rospy.get_param("~rp_param_path")
        
        with open(rp_param_path,'r') as f:
            self.rp_param = yaml.safe_load(f)

        self.space_poses = {}
        for space in self.rp_param["SPACE_POSES"]:
            self.space_poses[list(space.keys())[0]] = list(space.values())[0]

        self.look = {}
        for look_point in self.rp_param["SEAT_SUGGEST_POSES"]:
            self.look[list(look_point.keys())[0]] = list(look_point.values())[0]

        self.suggest_poses = {}
        for pose in self.rp_param["SEAT_SUGGEST_POSES"]:
            self.suggest_poses[list(pose.keys())[0]] = list(pose.values())[0]


    def calculate_distance(self, keypoint_1: Point, keypoint_2: Point):
        x = keypoint_1.x - keypoint_2.x
        y = keypoint_1.y - keypoint_2.y
        z = keypoint_1.z - keypoint_2.z
        distance = math.sqrt(x**2 + y**2 + z**2)
        return distance

    """ added by kawabata at 2024/5/30


    #     def getPersonCenter(self, person):
    #         left_shoulder = person.keypoints.left_shoulder
    #         right_shoulder = person.keypoints.right_shoulder
    #         shoulder_distance = self.calculate_distance(left_shoulder.point, right_shoulder.point)
    #         sit_score = person.score
    #         if left_shoulder.score < 0.5 or \
    #             right_shoulder.score < 0.5 or \
    #             shoulder_distance > 1.0 or \
    #             sit_score[0] < 0.4:
    #                 continue
    #         center_point = Point(
    #             (left_shoulder.point.x + right_shoulder.point.x) / 2.0,
    #             (left_shoulder.point.y + right_shoulder.point.y) / 2.0,
    #             (left_shoulder.point.z + right_shoulder.point.z) / 2.0
    #         )

    #         center_pose_from_map: Pose = self.tamtf.get_pose_with_offset(
    #             target_frame=self.description.frame.map,
    #             source_frame=self.description.frame.rgbd,
    #             offset = Pose(center_point, Quaternion(0,0,0,1)),
    #             buffer_frame="living_human")
    #             )

    #         return center_pose_from_map


    #     def judgInSameRoom(self, pose)
    #         req_room = GetAreaServiceRequest(
    #             position = Pose2D(
    #                 pose.position.x,
    #                 pose.position.y,
    #                 0.0
    #             )
    #         )
    #         res_room = self.srv_search_room(req_room)
            
    #         x, y, _ = locations.get_robot_position()
    #         req_room = GetAreaServiceRequest(
    #             position = Pose2D(
    #                 x,
    #                 y,
    #                 0.0
    #             )
    #         )
    #         my_room = self.srv_search_room(req_room)

    #         return res_room == my_room

    #     def detectSittngPeople(self):
    #         for try_num in range(trial_num):
    #             msg: Ax3DPoseWithLabelArray = rospy.wait_for_message("/mmaction2/poses/with_label", Ax3DPoseWithLabelArray)
    #             print(f"detect {len(msg.people)} person")
                
    #             left_shoulder = person.keypoints.left_shoulder
    #             right_shoulder = person.keypoints.right_shoulder
    #             shoulder_distance = self.calculate_distance(left_shoulder.point, right_shoulder.point)
    #             sit_score = person.score

    #             if left_shoulder.score < 0.5 or \
    #                 right_shoulder.score < 0.5 or \
    #                 shoulder_distance > 1.0 or \
    #                 sit_score[0] < 0.4:
    #                     continue
    #             else:
    #                 return msg.people

    #
    """


    # search full seat
    def detect_full_seat(self, space, trial_num=10):
        # {'SOFA_RIGHT': '(1.02, -1.07, 0.0)', 'SOFA_LEFT': '(1.02, -1.85, 0.0)', 'CHAIR_LEFT': '(2.61, 3.13, 0.0)','CHAIR_RIGHT': '(1.9, -3.13, 0.0)'}

        flags = {}
        for seat in space:
            flags[seat.keys()] = False

        sit_people = []
        for idx in range(trial_num):
            #msg: Ax3DPoseWithLabelArray = rospy.wait_for_message("/mmaction2/poses/with_label", Ax3DPoseWithLabelArray)
            try:
                msg: HumanCoordinatesArray = rospy.wait_for_message("/human_coordinates", HumanCoordinatesArray,timeout=1.0)
            except Exception as e:
                self.logdebug(f"{e}")
                continue

            print(f"detect {len(msg.human_coordinates_array)} person")
            for idy, detect_person in enumerate(msg.human_coordinates_array):
                print(detect_person)
                try:
                    #欲しいkeypointの値を辞書からフィタリング
                    keypoints = {kpt.name:kpt for kpt in detect_person.keypoints if kpt.name in ["LEFT_SHOULDER", "RIGHT_SHOULDER", "LEFT_WRIST", "RIGHT_WRIST"]}
                    if "LEFT_SHOULDER" not in keypoints or "RIGHT_SHOULDER" not in keypoints:
                        continue
                    left_shoulder = keypoints["LEFT_SHOULDER"]
                    right_shoulder = keypoints["RIGHT_SHOULDER"]

                    shoulder_distance = self.calculate_distance(left_shoulder.point, right_shoulder.point)
                    print(shoulder_distance)
                    if left_shoulder.score < 0.5 or right_shoulder.score < 0.5 or shoulder_distance > 1.0:
                            continue
                    center_point = Point(
                        (left_shoulder.point.x + right_shoulder.point.x) / 2.0,
                        (left_shoulder.point.y + right_shoulder.point.y) / 2.0,
                        (left_shoulder.point.z + right_shoulder.point.z) / 2.0
                    )

                    print(center_point)

                    try:
                        center_point_from_map = self.tamtf.get_pose_with_offset(
                            target_frame=self.description.frame.map,
                            source_frame=self.description.frame.rgbd,
                            offset=Pose(center_point, Quaternion(0,0,0,1)),
                            buffer_frame="human_entrance"
                        )
                    except Exception as e:
                        rospy.logwarn("Required keypoints not found")

                    print(center_point_from_map)

                except KeyError:
                    pass

                ##########人がいる部屋がどこの部屋かを返す##############
                req_room = GetAreaServiceRequest(
                    position = Pose2D(
                        center_point_from_map.position.x,
                        center_point_from_map.position.y,
                        0.0
                    )
                )
                res_room = self.srv_search_room(req_room)
                ###################################################
                print(res_room)

                ##########ロボットがいる部屋がどこの部屋かを返す#########
                robx, roby, _ = locations.get_robot_position()
                req_room = GetAreaServiceRequest(
                    position = Pose2D(
                        robx,
                        roby,
                        0.0
                    )
                )
                my_room = self.srv_search_room(req_room)
                ###################################################
                print(my_room)

                if res_room.area.data == my_room.area.data:
                    sit_people.append(Point(center_point_from_map.position.x, center_point_from_map.position.y, 0))

            if len(sit_people) != 0:
                # regard as a full seat by looking at the distance bethween a person and a seat
                print(sit_people)
                for seat in space:
                    seat = seat.values()
                    place_xyz = Point(seat[0], seat[1], 0)
                    for person_xyz in sit_people:
                        print(self.calculate_distance(place_xyz, person_xyz))
                        if self.calculate_distance(place_xyz, person_xyz) < self.rp_param["SEAT_PERSON_DIS_THRESH"]:
                            flags[list(seat.keys())[0]] = True

                print(flags)
                return flags
        # self.human_point_pub.publish(marker)
        return flags


# """  added by kawabata at 2024/5/30
#     def suggestFreeSpace(self, seat_flags={}):
#         done = False
#         process_cnt = rospy.get_param(rospy.get_name() + "/guest_count", 0)
#         guest_host_seat = rospy.get_param(rospy.get_name() + "/guest_host_seat", ["None", "None", GP_HOST_POSE])
#         guest_host_name = rospy.get_param(rospy.get_name() + "/guest_host_name", ["None","None", GP_HOST_NAME]) 
#         rospy.loginfo(seat_flags)

#         for seat, flag in seat_flags.items():
#             if flag != True:
#                 self.lme.run(goal = GP_SIT_POSES[seat], pose = GP_DEF_POSE)
#                 self.hsrif.whole_body.move_to_joint_positions(GP_SIT_POSE)
                
#                 txt = "Please have that seat."
#                 self.hsrif.tts.say(guest_host_name[process_cnt] + ", " + txt, language="en")
#                 rospy.sleep(2)
#                 self.hsrif.tts.say(guest_host_name[process_cnt] + ", " + txt, language="en")
                
#                 guest_host_seat[process_cnt] = seat
#                 rospy.set_param(rospy.get_name() + "/guest_host_seat", guest_host_seat)
#                 rospy.sleep(2)
                
#                 done = True
#                 break

#             else:
#                 pass

#         return done
# """


    def suggestFreeSpace(self,suggest_seat, suggest_pose):
        process_cnt = rospy.get_param(rospy.get_name() + "/guest_count", 0)
        guest_host_name = rospy.get_param(rospy.get_name() + "/guest_host_name", ["None","None", self.rp_param["HOST_NAME"]]) 
        rospy.loginfo(suggest_pose)

        print(suggest_seat)
        print(suggest_pose)

        self.lme.run(goal = Pose2D(x=suggest_pose[0],y=suggest_pose[1],theta=suggest_pose[2]), pose = self.rp_param["DEF_POSE"])
        self.hsrif.whole_body.move_to_joint_positions(self.rp_param["SIT_POSE"])

        if suggest_seat == "SOFA_RIGHT":
            txt = "Please take a seat on the right side of this sofa."
        elif suggest_seat == "SOFA_LEFT":
            txt = "Please take a seat on the left side of this sofa."
        else:
            txt = "Please take this seat."
        self.hsrif.tts.say(guest_host_name[process_cnt] + ", " + txt, language="en")
        rospy.sleep(2)
        self.hsrif.tts.say(guest_host_name[process_cnt] + ", " + txt, language="en")



# """ added by kawabata at 2024/5/30
#     def getFeatures(self, place):
#         attrs = numpy.array([0] * len(GP_RP_FEATURE_TRUE_CLASS))

#         for deg in range(-1, 1):
#             self.hsrif.whole_body.gaze_point(x = GP_SPACE_POSES[place].x,
#                                              y = GP_SPACE_POSES[place].y,
#                                              z = 1.0-0.2*deg,  # 角度どのぐらい変えるかを外からコントロールできるようにしたほうが良い
#                                              frame_id = "map")
            
#             imgMsg = rospy.wait_for_message('/hsrb/head_rgbd_sensor/rgb/image_raw', Image)
#             goal = GetAttrGoal(img=imgMsg)
#             self.action_client.send_goal(goal)
#             self.action_client.wait_for_result()
#             result = self.action_client.get_result()
            
#             attrs = numpy.array([attr.data for attr in result.attributes]) | attrs
            
#         attrs = attrs.tolist()
#         return attrs
# """


    def getFeature(self, seat_name):
        guest_host_seat = rospy.get_param(rospy.get_name() + "/guest_host_seat", ["None", "None", self.rp_param["HOST_SEAT"]])
        space_poses = {}
        for space in self.rp_param["SPACE_POSES"]:
            space_poses[list(space.keys())[0]] = list(space.values())[0]

        attrs = numpy.array([0] * len(self.rp_param["RP_FEATURE_TRUE_CLASS"]))
        for deg in range(-1, 1):
            self.hsrif.whole_body.gaze_point(x = space_poses[seat_name][0],
                                            y = space_poses[seat_name][1],
                                            z = 1.0-0.2*deg,
                                            frame_id = "map")

            imgMsg = rospy.wait_for_message('/hsrb/head_rgbd_sensor/rgb/image_raw', Image)
            goal = GetAttrGoal(img=imgMsg)
            self.action_client.send_goal(goal)
            self.action_client.wait_for_result()
            result = self.action_client.get_result()

            attrs = numpy.array([attr.data for attr in result.attributes]) or attrs

        attrs = attrs.tolist()
        return attrs

# """  added by kawabata at 2024/5/30

#     def detectFullSeat(self, space_list, trial_num=3):   

#         full_flags = {}
#         for seat in space_list:
#             full_flags[seat] = False

#         for try_num in trial_num:
#             sitting_people = self.detetSittingPeople()

#             if len(sitting_people) < len(GP_SPACE_POSES):
#                 break
        
#         for person in sitting_people:
#             person_pose_from_map = getCenterOfPerson(person)
    
#             if judgeInSameRoom(person_pose_from_map):
#                 sit_point = Point(person_pose_from_map.position.x, person_pose_from_map.position.y, 0)
#                 print(sit_point)
                
#                 # regard as a full seat by looking at the distance bethween a person and a seat
#                 for place in space_list:
#                     try:
#                         place_point = Point(GP_SPACE_POSES[place].x, GP_SPACE_POSES[place].y, 0)
#                         distance = self.calculate_distance(place_point, sit_point)
#                         print(distance)
#                         if distance < GP_SEAT_PERSON_DIS_THRESH:
#                             full_flags[place] = True
#                     except:
#                         pass
#             else:
#                 pass
            

#         return full_flags


#     def search(self, space_list, looking_list):
#         rospy.loginfo("will look at")
#         rospy.loginfo(looking_list)

#         seat_flags = {}
#         for seat in space_list:
#             seat_flags[seat] = False
             
#         txt = "I'm looking for a vacant seat."
#         self.hsrif.tts.say(txt, language="en")
        
#         for area in looking_list:
#             try:    
#                 print("looking at " + area)
#                 self.hsrif.whole_body.gaze_point(GP_LOOK_ATS[area][0],
#                                                  GP_LOOK_ATS[area][1],
#                                                  GP_LOOK_ATS[area][2],
#                                                 frame_id = "map")
                
#                 rospy.sleep(1)
                
#                 full_flags = self.detectFullSeat(space_list, trial_num=5)
#                 # rospy.sleep(1.0)
                

#                 seat_flags = full_flags or seat_flags

#             except:
#                 pass

#         return seat_flags # True == occupied, False == vacant

# """


    def calculate_nearby_seat(self,robx,roby,seat_dic):
        distance = 100.0
        for seat in seat_dic:
            if distance > math.sqrt((robx - seat[0])**2+(roby - seat[1])**2):
                suggest_space = seat
        return suggest_space


    def search(self, space, look):
        process_cnt = rospy.get_param(rospy.get_name() + "/guest_count", 0)
        # {'SOFA_RIGHT': '(1.02, -1.07, 0.0)', 'SOFA_LEFT': '(1.02, -1.85, 0.0)', 'CHAIR_LEFT': '(2.61, 3.13, 0.0)','CHAIR_RIGHT': '(1.9, -3.13, 0.0)'}
        # {'sofa': '(1.08, -1.39, 0.8),'}, {'chair_left': '(2.61, 3.13, 0.8),'}, {'chair_right': '(1.9, -3.13, 0.8)'}

        rospy.loginfo(look)
        space_flags = {}
        for seat in space:
            print(seat.keys())
            space_flags[seat.keys()] = False
        print(space_flags)
        txt = "I'm looking for a vacant seat."
        self.hsrif.tts.say(txt, language="en")

        for area in look:
            print("looking at " + str(area.keys()))
            point = area.values()
            print(point)
            x, y, z = point[0], point[1], point[2]
            print(str(x), str(y), str(z))
            self.hsrif.whole_body.gaze_point(point[0], point[1], point[2], frame_id = "map")

            rospy.sleep(1)

            space_flags = self.detect_full_seat(space, trial_num=3)
            # rospy.sleep(1.0)

            for seat in space:
                space_flags[list(seat.keys())[0]] = space_flags[list(seat.keys())[0]] or space_flags[list(seat.keys())[0]] # ここ「|」を「or」にしたほうがいいかも．colabで動作試した感じor動作してなかった．

            # 値がTrueであるキーをリスト化 {SOFA_RIGHT:True, SOFA_LEFT:True, CHAIR_KITCHEN:False,CHAIR_ENTRANCE:False}
            true_keys = [key for key, value in space_flags.items() if value]
            # 存在しうる人数を検出した時点でサーチング終了
            if len(true_keys) >= process_cnt+1:
                break

        #座っていないシートのキーをリスト化
        false_keys = [key for key, value in space_flags.items() if not value]
        suggest_point = {}
        for suggest_point_ in self.rp_param["SEAT_SUGGEST_POSES"]:
            for no_sit_seat in false_keys:
                if list(suggest_point.keys())[0] == no_sit_seat:
                    suggest_point[no_sit_seat] = suggest_point_.values()
        robx, roby, _ = locations.get_robot_position()

        #ロボットの座標と座っていない席の座標を投げて、一番近い席を返す関数
        suggest_seat = self.calculate_nearby_seat(robx,roby,suggest_point)
        return space_flags,suggest_seat



# """ added by kawabata at 2023/5/30
#     def filteringDict(self, dict, keys_to_get=None, values_to_get=None):

#         if keys_to_get != None:
#             return {key: val for key, val in dict.items() if key in keys_to_get}
#         elif values_to_get != None:
#             return {key: val for key, val in dict.items() if value in keys_to_get}
#         elif keys_to_get == None and values_to_get == None:
#             return {key: val for key, val in dict.items() if key in key_to_get and value in keys_to_get}
#         else:
#             print("There is no filter. Input dict is returned as it is.")
#             return dict

    
#     def execute(self, userdata):
#         # before_intro_pose = rospy.get_param(rospy.get_name() + "/before_intro_pose", GP_SEARCHING_POSE[0])   
#         process_cnt = rospy.get_param(rospy.get_name() + "/guest_count", 0)
#         guest_host_seat = rospy.get_param(rospy.get_name() + "/guest_host_seat", [GP_SPACE_LIST_MAIN[0],GP_SPACE_LIST_MAIN[1],GP_HOST_POSE])
#         guest_host_feature = rospy.get_param(rospy.get_name() + "/guest_host_feature", [[0]*len(GP_RP_FEATURE_TRUE_CLASS),
#                                                                                         [0]*len(GP_RP_FEATURE_TRUE_CLASS),
#                                                                                         [0]*len(GP_RP_FEATURE_TRUE_CLASS)])
#         there_is_unexpected_person = False

#         # 下2つは条件分岐で使えそうだから，一応用意してるって感じです
#         done_feature = False
#         done_suggest = False
        
#         #############################################
#         # ソファと椅子を見渡して，空いている場所を見つける
#         # 初回は，ホストの位置も認識する
#         #############################################

#         # 想定していない人（一回目ならホスト以外）が席に座っていると認知した場合を考慮して何度かトライできるようにしてる．
#         for try_num in range(2):
#             is_occupied_dict = self.search(GP_SPACE_LIST, GP_SPACE_POSES, GP_LOOKING_LIST)
#             occupied_dict = self.filteringDict(is_occupied_dict, values_to_get=[True])

#             if len(occupied_dict) == porcess_cnt+1:
#                 rospu.loginfo("There is no unexpected person.")
#                 break
#             else:
#                 rospy.loginfo("Unexpected person is counted.")
#                 unexpected_person_detected = True

#         if unexpected_person_detected: # これ使って例外処理といいますか，なんか別個で処理用意してもいいかもね．
#             pass

#         else:
#             # 一人目のゲストが来たときの動作
#             if process_cnt == 0:
#                 # 席が埋まっていた場所を見て特徴を抽出する
#                 for feature_cnt, seat_name, is_occupied in enumerate(occupied_dict.items()):
#                     feature_binary_list = self.getFeature(seat_name)
#                     guest_host_feature[-1] = self.getFeature(seat_name)
#                     guest_host_seat[-1] = seat_name
#                     rospy.loginfo("host's feature state:" + str(feature_binary_list))

#                     if feature_cnt == process_cnt+1:
#                         done_feature = True
#                         break

#             else:
#                 # 席が埋まっていた場所を見て特徴を抽出し，特徴のハミング距離からどの席に誰がいるか判断
#                 for person_id in range(-1, process_cnt):  
#                     similarity_dist_dict = {}

#                     for feature_cnt, seat_name, is_occupied in neumerate(occupied_dict.items()):
#                         feature_binary_list = self.getFeature(seat_name)
#                         similarity_dist_dict[seat_name] = (distance.hamming(feature_binary_list, guest_host_feature[-1+feature_cnt]))

#                         if feature_cnt == process_cnt+1:
#                             break

#                     gest_host_seat[person_id] = max(similarity_dist_dict, key=similarity_dist_dict.get)

#                 done_feature = True

#             # 席を提案する
#             done_suggest = self.suggestFreeSpace(is_occupied_dict)

#             rospy.set_param(rospy.get_name() + "/guest_host_feature", guest_host_feature)
#             rospy.set_param(rospy.get_name() + "/guest_host_seat", guest_host_seat)


#             if done_suggest == False: # 満席席提案ができなかった
#                 rospy.loginfo("There is no vacant seat.")
#                 # 何かしら処理用意してもいいかもね

#             elif done_suggest and done_feature:
#                 return "next"
                
#             else:
#                 return "loop"

# """





    def execute(self, userdata):
        # before_intro_pose = rospy.get_param(rospy.get_name() + "/before_intro_pose", GP_SEARCHING_POSE[0])   
        process_cnt = rospy.get_param(rospy.get_name() + "/guest_count", 0)

        guest_host_seat = rospy.get_param(rospy.get_name() + "/guest_host_seat", [rospy.set_param(rospy.get_name() + "/guest_host_seat", [self.rp_param["SPACE_POSES"][0]["SOFA_RIGHT"],self.rp_param["SPACE_POSES"][1]["SOFA_LEFT"],self.rp_param["HOST_SEAT"]])])
        guest_host_feature = rospy.get_param(rospy.get_name() + "/guest_host_feature", [[0]*len(self.rp_param["RP_FEATURE_TRUE_CLASS"]),
                                                                                        [0]*len(self.rp_param["RP_FEATURE_TRUE_CLASS"]),
                                                                                        [0]*len(self.rp_param["RP_FEATURE_TRUE_CLASS"])])

        #############################################
        # ソファと椅子を見渡して，空いている場所を見つける
        # 初回は，ホストの位置も認識する
        #############################################


        print(self.space_poses)
        print(self.look)
        print(self.suggest_poses)

        # [{'SOFA_RIGHT': '(1.02, -1.07, 0.0)'}, {'SOFA_LEFT': '(1.02, -1.85, 0.0)'}, {'CHAIR_LEFT': '(2.61, 3.13, 0.0)'}, {'CHAIR_RIGHT': '(1.9, -3.13, 0.0)'}]
        # [{'sofa': '(1.08, -1.39, 0.8),'}, {'chair_left': '(2.61, 3.13, 0.8),'}, {'chair_right': '(1.9, -3.13, 0.8)'}]
        # [{'SOFA_RIGHT': '(2.144, -1.544, 2.966)'}, {'SOFA_LEFT': '(1.784, -2.269, 2.865)'}, {'CHAIR_LEFT': '(2.993, -2.594, -1.718)'}, {'CHAIR_RIGHT': '(2.22, -2.386, -1.868)'}]

        space_flags , suggest_seat = self.search(self.space_poses, self.look)

        if process_cnt == 0:
            for look_seat_name in space_flags:
                feature_binary_list = self.getFeature(look_seat_name.keys())
                guest_host_feature[-1] = feature_binary_list
                guest_host_seat[-1] = look_seat_name.keys()
                rospy.loginfo("host's feature state:" + str(feature_binary_list))

        else:
            feature_dic = {}
            for look_seat_name in space_flags:
                feature_dic[list(look_seat_name.keys)[0]] = self.getFeature(look_seat_name.keys())

            rospy.loginfo("I got attributes:" + str(feature_dic))
            rospy.loginfo("host's attributes:" + str(guest_host_feature[-1]))
            rospy.loginfo("guest1's attributes:" + str(guest_host_feature[0]))


            for person_feature in feature_dic:
                match_with_host = distance.hamming(person_feature.values(),guest_host_feature[-1])
                match_with_guest1 = distance.hamming(person_feature.values(),guest_host_feature[0])
                if match_with_host > match_with_guest1:
                    guest_host_seat[2] = person_feature.keys()
                else:
                    guest_host_seat[0] = person_feature.keys()


        self.suggestFreeSpace(suggest_seat,self.suggest_poses[suggest_seat])
        if process_cnt == 0:
            guest_host_seat[0] = suggest_seat
        else:
            guest_host_seat[1] = suggest_seat

        rospy.set_param(rospy.get_name() + "/guest_host_seat", guest_host_seat)
        rospy.set_param(rospy.get_name() + "/guest_host_feature", guest_host_feature)

        return "next"



        # for cnt, (space, looking, sit) in enumerate(zip(self.rp_param["SPACE_POSES"], self.rp_param["LOOK_ATS"], self.rp_param["SEAT_SUGGEST_POSES"])):
        #     print(space)
        #     print(looking)
        #     print(sit)
        #     full_seat_flags = self.search(space, looking)
        #     print(full_seat_flags)

        #     for flag in full_seat_flags.items():
        #         #if (flag[1] == True) & (self.not_done_feature == True) & (flag[0] != guest_host_seat[process_cnt]):   
        #         if (flag[1] == True) & (self.not_done_feature == True) :                     
        #             person_attrs = self.getFeature(space)
                    
        #             # 一人目
        #             if process_cnt == 0:                       
        #                 feature_cnt += 1
        #                 rospy.loginfo("host's attributes:" + str(person_attrs))
                        
        #                 guest_host_feature[2] = person_attrs
        #                 guest_host_seat[2] =  flag[0]
        #                 print(guest_host_seat)
                        
        #                 rospy.set_param(rospy.get_name() + "/guest_host_feature", guest_host_feature)
        #                 rospy.set_param(rospy.get_name() + "/guest_host_seat", guest_host_seat)
                        
        #                 if feature_cnt == 1:
        #                     self.not_done_feature = False
                        
        #                 # self.not_done_suggest = False
        #                 # self.not_done_suggest = self.suggestFreeSpace(sit, full_seat_flags)
        #                 # self.hsrif.whole_body.move_to_go()
        #                 # self.hsrif.gripper.command(0)
        #                 # rospy.sleep(1)

        #             else:        
        #                 feature_cnt += 1
        #                 rospy.loginfo("I got attributes:" + str(person_attrs))
        #                 rospy.loginfo("host's attributes:" + str(guest_host_feature[2]))
        #                 rospy.loginfo("guest0's attributes:" + str(guest_host_feature[0]))
                        
        #                 if distance.hamming(person_attrs, guest_host_feature[0]) > distance.hamming(person_attrs, guest_host_feature[2]):
        #                     guest_host_seat[0] = flag[0]
        #                     rospy.loginfo("guest0 is on " + flag[0])
        #                 else:
        #                     guest_host_seat[2] = flag[0]
        #                     rospy.loginfo("host is on " + flag[0])
        #                 rospy.set_param(rospy.get_name() + "/guest_host_seat", guest_host_seat)
        #                 rospy.set_param(rospy.get_name() + "/guest_host_feature", guest_host_feature)
                
        #                 if feature_cnt == 2:
        #                     self.not_done_feature = False

        #     if self.not_done_suggest == True:
        #         self.not_done_suggest = False
        #         self.not_done_suggest = self.suggestFreeSpace(sit, full_seat_flags)
        #         self.hsrif.whole_body.move_to_go()
        #         self.hsrif.gripper.command(0)
        #         rospy.sleep(1)

        #     if (self.not_done_feature != True)  or (self.not_done_suggest != True):
        #         rospy.loginfo(guest_host_seat)
        #         self.not_done_feature = True
        #         self.not_done_suggest = True
        #         return "next"
                    
            # try:      
            #     self.lme.run(goal = GP_SEARCHING_POSE[cnt+1], pose = GP_SEARCH_AREA_POSE)
                
            # except IndexError:
            #     self.hsrif.tts.say("Let me try again.", language="en")
            #     rospy.sleep(1)
            #     self.lme.run(goal = GP_SEARCHING_POSE[0], pose = GP_SEARCH_AREA_POSE)
            #     break
            
       # return "loop"
