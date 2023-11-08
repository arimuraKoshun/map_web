// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice

#ifndef MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_H_
#define MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'lat'
// Member 'lng'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/PointRequest in the package map_service.
typedef struct map_service__srv__PointRequest_Request
{
  rosidl_runtime_c__double__Sequence lat;
  rosidl_runtime_c__double__Sequence lng;
} map_service__srv__PointRequest_Request;

// Struct for a sequence of map_service__srv__PointRequest_Request.
typedef struct map_service__srv__PointRequest_Request__Sequence
{
  map_service__srv__PointRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_service__srv__PointRequest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/PointRequest in the package map_service.
typedef struct map_service__srv__PointRequest_Response
{
  rosidl_runtime_c__String message;
} map_service__srv__PointRequest_Response;

// Struct for a sequence of map_service__srv__PointRequest_Response.
typedef struct map_service__srv__PointRequest_Response__Sequence
{
  map_service__srv__PointRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_service__srv__PointRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_H_
