// In the following example, markers appear when the user clicks on the map.
// Each marker is labeled with a single alphabetical character.
var map;
const labels = [];
for (var i = 1; i <= 20; i++) {
  labels.push(i.toString());
}
let labelIndex = 0;
var markers = [];
var log_rows = [];

var rightsidebar = document.getElementById("right-sidebar");

var send_lat = [];
var send_long = [];

function initMap() {
  const bangalore = { lat: 33.655198, lng:130.673920 };
    map = new google.maps.Map(document.getElementById("map"), {
    zoom: 18,
    center: bangalore,
    mapTypeId: 'satellite',
    tilt: 0,
  });

  // This event listener calls addMarker() when the map is clicked.
  google.maps.event.addListener(map, "click", (event) => {
    addMarker(event.latLng, map);
    show_distance();
  });

  google.maps.event.addListener(map, "rightclick", (event) => {
    removeMarker(event.latLng, map);
  });
  
}

function addcurrentposition(){
  var marker = new google.maps.Marker({
    position: location,
    label: labels[labelIndex++ % labels.length],
    map: map,
    //draggable: true
  });

  markers.push(marker);
  send_lat.push(location.lat());
  send_long.push(location.lng());

  // 新しい行を作成して情報を追加
  var newLine = document.createElement("p");
  newLine.innerHTML = "pose" + labelIndex + "-------------------------" +  "<br>lat: " + location.lat() + "<br>lng: " + location.lng()+ "<br>---------------------------------" ;
  log_rows.push(newLine);
  // HTML要素に新しい行を追加
  rightsidebar.appendChild(newLine);
}

// Adds a marker to the map.
function addMarker(location, map) {
  // Add the marker at the clicked location, and add the next-available label
  // from the array of alphabetical characters.
  var marker = new google.maps.Marker({
    position: location,
    label: labels[labelIndex++ % labels.length],
    map: map,
    //draggable: true
  });

  markers.push(marker);
  send_lat.push(location.lat());

  send_long.push(location.lng());
  send_lng.push(location.lng());


  // 新しい行を作成して情報を追加
  var newLine = document.createElement("p");
  newLine.innerHTML = "pose" + labelIndex + "-------------------------" +  "<br>lat: " + location.lat() + "<br>lng: " + location.lng()+ "<br>---------------------------------" ;
  log_rows.push(newLine);
  // HTML要素に新しい行を追加
  rightsidebar.appendChild(newLine);

}

function show_distance() {
  if (markers.length < 2) {
    document.getElementById("distance").innerHTML = "Not enough markers.";
    return;
  }

  var latLng1 = markers[markers.length - 2].getPosition();
  var latLng2 = markers[markers.length - 1].getPosition();

  var distance = google.maps.geometry.spherical.computeDistanceBetween(
    latLng1,
    latLng2
  );

  document.getElementById("distance").innerHTML =
    "Distance: " + distance.toFixed(2) + " meters";
}

function removeMarker() {
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
}

window.initMap = initMap;
