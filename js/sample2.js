// Create ros object to communicate over your Rosbridge connection
const ros = new ROSLIB.Ros({
    url: 'ws://192.168.1.31:9090',
    options: {
      ros_domain_id: '30' // ROS_DOMAIN_IDを設定する
    }
  });

  // When the Rosbridge server connects, fill the span with id "status" with "successful"
  ros.on("connection", () => {
    document.getElementById("status").innerHTML = "successful";
    console.log('Connected to ROSBridge WebSocket server.');
  });

  // When the Rosbridge server experiences an error, fill the "status" span with the returned error
  ros.on('error', function(error) {
    console.log('Error connecting to ROSBridge WebSocket server: ', error);
  });

  // When the Rosbridge server shuts down, fill the "status" span with "closed"
  ros.on('close', function() {
    console.log('Connection to ROSBridge WebSocket server closed.');
  });

  var imageTopic = new ROSLIB.Topic({
    ros: ros,
    name: '/camera/image_raw',  // カメラ画像のトピック名に合わせて変更
    messageType: 'sensor_msgs/msg/Image'  // トピックのメッセージ型に合わせて変更
  });

  imageTopic.subscribe(function(message) {
    console.log('Received image');
    // メッセージを受信したときの処理をここに書く
    var imageData = "data:image/png;base64," + message.data;  // 画像データをデータURLに変換

    // 画像をブラウザに表示
    document.getElementById('camera_image').setAttribute('src', imageData); 
  });
  /*
        const cmdVel = new ROSLIB.Topic({
      ros: ros,
      name: '/cmd_vel',
      messageType: 'geometry_msgs/Twist'
    });

    const pad = document.getElementById('pad');
    const handle = document.getElementById('handle');

    let twist = new ROSLIB.Message({
      linear: { x: 0, y: 0, z: 0 },
      angular: { x: 0, y: 0, z: 0 }
    });

    let padRect = pad.getBoundingClientRect();

    handle.addEventListener('mousedown', (e) => {
      e.preventDefault();
      document.addEventListener('mousemove', moveHandle);
      document.addEventListener('mouseup', stopHandle);
    });

    function moveHandle(e) {
      let x = e.clientX - padRect.left - handle.offsetWidth / 2;
      let y = e.clientY - padRect.top - handle.offsetHeight / 2;
      let r = (pad.offsetWidth - handle.offsetWidth) / 2;
      let cx = r, cy = r;

      let dist = Math.sqrt(Math.pow(x - cx, 2) + Math.pow(y - cy, 2));
      if (dist > r) {
        x = (x - cx) * r / dist + cx;
        y = (y - cy) * r / dist + cy;
      }

      handle.style.left = x + 'px';
      handle.style.top = y + 'px';

      let nx = ((x - cx) / r);
      let ny = ((cy - y) / r);
      twist.linear.x = parseFloat(ny.toFixed(3));
      twist.angular.z = -parseFloat(nx.toFixed(3));
      cmdVel.publish(twist);
    }

    function stopHandle(e) {
      document.removeEventListener('mousemove', moveHandle);
      document.removeEventListener('mouseup', stopHandle);
      handle.style.left = '125px';
      handle.style.top = '125px';
      twist.linear.x = 0;
      twist.angular.z = 0;
      cmdVel.publish(twist);
    }*/

       // Calling a service
      // -----------------

      var gps = new ROSLIB.Topic({
        ros : ros,
        name : '/gps/fix',
        messageType : 'sensor_msgs/NavSatFix'
      });

      var i=0;

      // // アイコンのURLを指定
      // var iconUrl = 'map_web/bunker.png'; // この部分にアイコンのURLを設定

      // // カスタムアイコンを作成
      // var customIcon = {
      //   url: iconUrl,
      //   scaledSize: new google.maps.Size(50, 50), // アイコンのサイズを設定
      // };
      

      gps.subscribe(function(message){
        i++;
        lat = message.latitude;
        long = message.longitude;
        if(i%10==0){
          var marker = new google.maps.Marker({
            position: { lat: message.latitude, lng: message.longitude },
            map: map,
            //draggable: true
          });
          console.log('Received GPS Fix Data:');
          console.log('Latitude: ' + message.latitude);
          console.log('Longitude: ' + message.longitude);
          console.log('Altitude: ' + message.altitude);
         // gps.unsubscribe();
        }

                 // ブラウザにデータを表示
      var displayDiv = document.getElementById('gps_data_display');  // HTML内の表示する要素を指定
      displayDiv.innerHTML = 'Latitude: ' + message.latitude + '<br>' +
                      'Longitude: ' + message.longitude + '<br>' +
                      'Altitude: ' + message.altitude;
      });


      var callServiceButton = document.getElementById('call_service_button');
      callServiceButton.addEventListener('click', function() {
    
        var addTwoIntsClient = new ROSLIB.Service({
          ros : ros,
          name : '/receive_point',
          serviceType : 'map_service/Mappoint'
        });
      
        var request = new ROSLIB.ServiceRequest({
          lat : lat,
          lon : long
        });
      
        addTwoIntsClient.callService(request, function(result) {
          console.log('Result for service call on '
            + addTwoIntsClient.name
            + ': '
            + result.message);
        });
      });


/*
      var cmd_vel = new ROSLIB.Topic({
        ros : ros,
        name : '/cmd_vel',
        messageType : 'geometry_msgs/Twist'
      });

      cmd_vel.subscribe(function(message){
        console.log('Received cmd_vel Data:');
        console.log('Linear Velocity (x): ' + message.linear.x);
        console.log('Angular Velocity (z): ' + message.angular.z);
      });
*/      