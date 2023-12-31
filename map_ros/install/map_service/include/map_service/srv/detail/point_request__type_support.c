// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "map_service/srv/detail/point_request__rosidl_typesupport_introspection_c.h"
#include "map_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "map_service/srv/detail/point_request__functions.h"
#include "map_service/srv/detail/point_request__struct.h"


// Include directives for member types
// Member `lat`
// Member `lng`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  map_service__srv__PointRequest_Request__init(message_memory);
}

void PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_fini_function(void * message_memory)
{
  map_service__srv__PointRequest_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_member_array[2] = {
  {
    "lat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_service__srv__PointRequest_Request, lat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lng",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_service__srv__PointRequest_Request, lng),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_members = {
  "map_service__srv",  // message namespace
  "PointRequest_Request",  // message name
  2,  // number of fields
  sizeof(map_service__srv__PointRequest_Request),
  PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_member_array,  // message members
  PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_type_support_handle = {
  0,
  &PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Request)() {
  if (!PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_type_support_handle.typesupport_identifier) {
    PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PointRequest_Request__rosidl_typesupport_introspection_c__PointRequest_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "map_service/srv/detail/point_request__rosidl_typesupport_introspection_c.h"
// already included above
// #include "map_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "map_service/srv/detail/point_request__functions.h"
// already included above
// #include "map_service/srv/detail/point_request__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  map_service__srv__PointRequest_Response__init(message_memory);
}

void PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_fini_function(void * message_memory)
{
  map_service__srv__PointRequest_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_member_array[1] = {
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_service__srv__PointRequest_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_members = {
  "map_service__srv",  // message namespace
  "PointRequest_Response",  // message name
  1,  // number of fields
  sizeof(map_service__srv__PointRequest_Response),
  PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_member_array,  // message members
  PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_type_support_handle = {
  0,
  &PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_service
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Response)() {
  if (!PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_type_support_handle.typesupport_identifier) {
    PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PointRequest_Response__rosidl_typesupport_introspection_c__PointRequest_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "map_service/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "map_service/srv/detail/point_request__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_members = {
  "map_service__srv",  // service namespace
  "PointRequest",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_Request_message_type_support_handle,
  NULL  // response message
  // map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_Response_message_type_support_handle
};

static rosidl_service_type_support_t map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_type_support_handle = {
  0,
  &map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_service
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest)() {
  if (!map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_type_support_handle.typesupport_identifier) {
    map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_service, srv, PointRequest_Response)()->data;
  }

  return &map_service__srv__detail__point_request__rosidl_typesupport_introspection_c__PointRequest_service_type_support_handle;
}
