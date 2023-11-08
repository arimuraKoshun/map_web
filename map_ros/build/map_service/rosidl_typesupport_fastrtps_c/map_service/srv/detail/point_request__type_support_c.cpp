// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice
#include "map_service/srv/detail/point_request__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "map_service/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "map_service/srv/detail/point_request__struct.h"
#include "map_service/srv/detail/point_request__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // lat, lng
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // lat, lng

// forward declare type support functions


using _PointRequest_Request__ros_msg_type = map_service__srv__PointRequest_Request;

static bool _PointRequest_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PointRequest_Request__ros_msg_type * ros_message = static_cast<const _PointRequest_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: lat
  {
    size_t size = ros_message->lat.size;
    auto array_ptr = ros_message->lat.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: lng
  {
    size_t size = ros_message->lng.size;
    auto array_ptr = ros_message->lng.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _PointRequest_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PointRequest_Request__ros_msg_type * ros_message = static_cast<_PointRequest_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: lat
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->lat.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->lat);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->lat, size)) {
      return "failed to create array for field 'lat'";
    }
    auto array_ptr = ros_message->lat.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: lng
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->lng.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->lng);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->lng, size)) {
      return "failed to create array for field 'lng'";
    }
    auto array_ptr = ros_message->lng.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_service
size_t get_serialized_size_map_service__srv__PointRequest_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PointRequest_Request__ros_msg_type * ros_message = static_cast<const _PointRequest_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name lat
  {
    size_t array_size = ros_message->lat.size;
    auto array_ptr = ros_message->lat.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lng
  {
    size_t array_size = ros_message->lng.size;
    auto array_ptr = ros_message->lng.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PointRequest_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_map_service__srv__PointRequest_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_service
size_t max_serialized_size_map_service__srv__PointRequest_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: lat
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: lng
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PointRequest_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_map_service__srv__PointRequest_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PointRequest_Request = {
  "map_service::srv",
  "PointRequest_Request",
  _PointRequest_Request__cdr_serialize,
  _PointRequest_Request__cdr_deserialize,
  _PointRequest_Request__get_serialized_size,
  _PointRequest_Request__max_serialized_size
};

static rosidl_message_type_support_t _PointRequest_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PointRequest_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_service, srv, PointRequest_Request)() {
  return &_PointRequest_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "map_service/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "map_service/srv/detail/point_request__struct.h"
// already included above
// #include "map_service/srv/detail/point_request__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // message
#include "rosidl_runtime_c/string_functions.h"  // message

// forward declare type support functions


using _PointRequest_Response__ros_msg_type = map_service__srv__PointRequest_Response;

static bool _PointRequest_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PointRequest_Response__ros_msg_type * ros_message = static_cast<const _PointRequest_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: message
  {
    const rosidl_runtime_c__String * str = &ros_message->message;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _PointRequest_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PointRequest_Response__ros_msg_type * ros_message = static_cast<_PointRequest_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->message.data) {
      rosidl_runtime_c__String__init(&ros_message->message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'message'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_service
size_t get_serialized_size_map_service__srv__PointRequest_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PointRequest_Response__ros_msg_type * ros_message = static_cast<const _PointRequest_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->message.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _PointRequest_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_map_service__srv__PointRequest_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_service
size_t max_serialized_size_map_service__srv__PointRequest_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: message
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _PointRequest_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_map_service__srv__PointRequest_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PointRequest_Response = {
  "map_service::srv",
  "PointRequest_Response",
  _PointRequest_Response__cdr_serialize,
  _PointRequest_Response__cdr_deserialize,
  _PointRequest_Response__get_serialized_size,
  _PointRequest_Response__max_serialized_size
};

static rosidl_message_type_support_t _PointRequest_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PointRequest_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_service, srv, PointRequest_Response)() {
  return &_PointRequest_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "map_service/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "map_service/srv/point_request.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PointRequest__callbacks = {
  "map_service::srv",
  "PointRequest",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_service, srv, PointRequest_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_service, srv, PointRequest_Response)(),
};

static rosidl_service_type_support_t PointRequest__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PointRequest__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_service, srv, PointRequest)() {
  return &PointRequest__handle;
}

#if defined(__cplusplus)
}
#endif
