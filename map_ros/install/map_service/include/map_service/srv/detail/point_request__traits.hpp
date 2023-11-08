// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice

#ifndef MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__TRAITS_HPP_
#define MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__TRAITS_HPP_

#include "map_service/srv/detail/point_request__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<map_service::srv::PointRequest_Request>()
{
  return "map_service::srv::PointRequest_Request";
}

template<>
inline const char * name<map_service::srv::PointRequest_Request>()
{
  return "map_service/srv/PointRequest_Request";
}

template<>
struct has_fixed_size<map_service::srv::PointRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_service::srv::PointRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<map_service::srv::PointRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<map_service::srv::PointRequest_Response>()
{
  return "map_service::srv::PointRequest_Response";
}

template<>
inline const char * name<map_service::srv::PointRequest_Response>()
{
  return "map_service/srv/PointRequest_Response";
}

template<>
struct has_fixed_size<map_service::srv::PointRequest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_service::srv::PointRequest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<map_service::srv::PointRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<map_service::srv::PointRequest>()
{
  return "map_service::srv::PointRequest";
}

template<>
inline const char * name<map_service::srv::PointRequest>()
{
  return "map_service/srv/PointRequest";
}

template<>
struct has_fixed_size<map_service::srv::PointRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<map_service::srv::PointRequest_Request>::value &&
    has_fixed_size<map_service::srv::PointRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<map_service::srv::PointRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<map_service::srv::PointRequest_Request>::value &&
    has_bounded_size<map_service::srv::PointRequest_Response>::value
  >
{
};

template<>
struct is_service<map_service::srv::PointRequest>
  : std::true_type
{
};

template<>
struct is_service_request<map_service::srv::PointRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<map_service::srv::PointRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__TRAITS_HPP_
