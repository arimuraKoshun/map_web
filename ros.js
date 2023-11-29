// Create ros object to communicate over your Rosbridge connection
const ros = new ROSLIB.Ros({
    url: 'ws://192.168.1.31:9090',
    options: {
      ros_domain_id: '30' // ROS_DOMAIN_ID繧定ｨｭ螳壹☆繧?
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
    name: '/camera/image_raw',  // 繧ｫ繝｡繝ｩ逕ｻ蜒上?ｮ繝医ヴ繝?繧ｯ蜷阪↓蜷医ｏ縺帙※螟画峩
    messageType: 'sensor_msgs/msg/Image'  // 繝医ヴ繝?繧ｯ縺ｮ繝｡繝?繧ｻ繝ｼ繧ｸ蝙九↓蜷医ｏ縺帙※螟画峩
  });

  imageTopic.subscribe(function(message) {
    console.log('Received image');
    // 繝｡繝?繧ｻ繝ｼ繧ｸ繧貞女菫｡縺励◆縺ｨ縺阪?ｮ蜃ｦ逅?繧偵％縺薙↓譖ｸ縺?
    var imageData = "data:image/png;base64," + message.data;  // 逕ｻ蜒上ョ繝ｼ繧ｿ繧偵ョ繝ｼ繧ｿURL縺ｫ螟画鋤

    // 逕ｻ蜒上ｒ繝悶Λ繧ｦ繧ｶ縺ｫ陦ｨ遉ｺ
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
      var j=0;
      var lat_sum=0, lon_sum=0;
      var start_lat, start_lon;
      var lat,long;

      // // 繧｢繧､繧ｳ繝ｳ縺ｮURL繧呈欠螳?
      // var iconUrl = 'map_web/bunker.png'; // 縺薙?ｮ驛ｨ蛻?縺ｫ繧｢繧､繧ｳ繝ｳ縺ｮURL繧定ｨｭ螳?

      // // 繧ｫ繧ｹ繧ｿ繝?繧｢繧､繧ｳ繝ｳ繧剃ｽ懈??
      // var customIcon = {
      //   url: iconUrl,
      //   scaledSize: new google.maps.Size(50, 50), // 繧｢繧､繧ｳ繝ｳ縺ｮ繧ｵ繧､繧ｺ繧定ｨｭ螳?
      // };


      gps.subscribe(function(message){
        i++;
        j++;
        lat = message.latitude;
        long = message.longitude;
        if(i%20==0){
          var marker = new google.maps.Marker({
            position: { lat: message.latitude, lng: message.longitude },
            map: map,
            //draggable: true
            icon: {
              path: google.maps.SymbolPath.CIRCLE,
              fillColor: '#0000FF', // マーカーの塗りつぶし色
              fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
              strokeColor: '#FFFFFF', // マーカーの境界線の色
              strokeWeight: 2,       // マーカーの境界線の太さ
              scale: 5             // マーカーサイズの調整
            }
          });
          // console.log('Received GPS Fix Data:');
          // console.log('Latitude: ' + message.latitude);
          // console.log('Longitude: ' + message.longitude);
          // console.log('Altitude: ' + message.altitude);
         // gps.unsubscribe();
        }
        lat_sum += message.latitude;
        lon_sum += message.longitude;
        if(j>=30){
          start_lat = lat_sum/30;
          start_lon = lon_sum/30;
          lat_sum = 0;
          lon_sum = 0;
          j = 0;
        }

                 // 繝悶Λ繧ｦ繧ｶ縺ｫ繝?繝ｼ繧ｿ繧定｡ｨ遉ｺ
        var displayDiv = document.getElementById('gps_data_display');  // HTML蜀?縺ｮ陦ｨ遉ｺ縺吶ｋ隕∫ｴ?繧呈欠螳?
        displayDiv.innerHTML = 'Latitude: ' + message.latitude + '<br>' +
                        'Longitude: ' + message.longitude + '<br>' +
                        'Altitude: ' + message.altitude;
      });

      var startSetButton = document.getElementById('start_position_set');
      startSetButton.addEventListener('click',function() {
        console.log('start set');
        let zone = xyzone(start_lat, start_lon);
        let target1 = xy2latlon(0,20,zone);
        let target2 = xy2latlon(-20,20,zone);
        let target3 = xy2latlon(0,40,zone);
        let target4 = xy2latlon(-20,40,zone);

        send_lat.push(target1[0]);
        send_long.push(target1[1]);
        send_lat.push(start_lat);
        send_long.push(start_lon)
        send_lat.push(target2[0]);
        send_long.push(target2[1]);
        send_lat.push(start_lat);
        send_long.push(start_lon)
        send_lat.push(target3[0]);
        send_long.push(target3[1]);
        send_lat.push(start_lat);
        send_long.push(start_lon)
        send_lat.push(target4[0]);
        send_long.push(target4[1]);
        send_lat.push(start_lat);
        send_long.push(start_lon)


        var marker = new google.maps.Marker({
          position: { lat: target4[0], lng: target4[1] },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            fillColor: '#00FF00', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 10             // マーカーサイズの調整
          }
        });

        var marker = new google.maps.Marker({
          position: { lat: target1[0], lng: target1[1] },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            fillColor: '#00FF00', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 10             // マーカーサイズの調整
          }
        });

        var marker = new google.maps.Marker({
          position: { lat: target2[0], lng: target2[1] },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            fillColor: '#00FF00', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 10             // マーカーサイズの調整
          }
        });

        var marker = new google.maps.Marker({
          position: { lat: target3[0], lng: target3[1] },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            fillColor: '#00FF00', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 10             // マーカーサイズの調整
          }
        });

        var marker = new google.maps.Marker({
          position: { lat: start_lat, lng: start_lon },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            fillColor: '#FF0000', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 10             // マーカーサイズの調整
          }
        });
      });

      var wayposition = document.getElementById('set_waypoint');
      wayposition.addEventListener('click',function() {
        send_lat.push(lat);
        send_long.push(long);
        var marker = new google.maps.Marker({
          position: { lat: lat, lng: long },
          map: map,
          //draggable: true
          icon: {
            path: google.maps.SymbolPath.BACKWARD_CLOSED_ARROW,
            fillColor: '#00FF00', // マーカーの塗りつぶし色
            fillOpacity: 1,      // 塗りつぶしの透明度 (0 から 1 まで)
            strokeColor: '#FFFFFF', // マーカーの境界線の色
            strokeWeight: 2,       // マーカーの境界線の太さ
            scale: 5             // マーカーサイズの調整
          }
        });
        markers.push(marker);
        labelIndex++;
        // 新しい行を作成して情報を追加
        var newLine = document.createElement("p");
        newLine.innerHTML = "pose" + labelIndex + "-------------------------" +  "<br>lat: " + lat + "<br>lng: " + long+ "<br>---------------------------------" ;
        log_rows.push(newLine);
        // HTML要素に新しい行を追加
        rightsidebar.appendChild(newLine);
      });

      var startSetButton = document.getElementById('cansel_waypoint');
      startSetButton.addEventListener('click',function() {
        labelIndex--;
        if (markers.length > 0) {
          var lastMarker = markers.pop(); // 配列から最後の要素を削除し、その要素を取得
          lastMarker.setMap(null); // マーカーを地図から削除
        }

        if(send_lat.length > 0) {
          send_lat.pop();
          send_long.pop();
        }

        if (log_rows.length > 0) {
          // 配列から最も新しい行を削除
          log_rows.pop();

          // 対応するHTML要素も削除
          rightsidebar.removeChild(rightsidebar.lastChild);
        }
      });

      var callServiceButton = document.getElementById('call_service_button');
      callServiceButton.addEventListener('click', function() {
        console.log('send_lat: ' + send_lat);
        console.log('send_long: ' + send_long);

        var addTwoIntsClient = new ROSLIB.Service({
          ros : ros,
          name : '/receive_point',
          serviceType : 'map_service/Mappoint'
        });

        var request = new ROSLIB.ServiceRequest({
          lat : send_lat,
          lng : send_long
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
