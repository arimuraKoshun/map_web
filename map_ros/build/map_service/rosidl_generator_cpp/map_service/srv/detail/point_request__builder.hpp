// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice

#ifndef MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__BUILDER_HPP_
#define MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__BUILDER_HPP_

#include "map_service/srv/detail/point_request__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace map_service
{

namespace srv
{

namespace builder
{

class Init_PointRequest_Request_lng
{
public:
  explicit Init_PointRequest_Request_lng(::map_service::srv::PointRequest_Request & msg)
  : msg_(msg)
  {}
  ::map_service::srv::PointRequest_Request lng(::map_service::srv::PointRequest_Request::_lng_type arg)
  {
    msg_.lng = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_service::srv::PointRequest_Request msg_;
};

class Init_PointRequest_Request_lat
{
public:
  Init_PointRequest_Request_lat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointRequest_Request_lng lat(::map_service::srv::PointRequest_Request::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_PointRequest_Request_lng(msg_);
  }

private:
  ::map_service::srv::PointRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_service::srv::PointRequest_Request>()
{
  return map_service::srv::builder::Init_PointRequest_Request_lat();
}

}  // namespace map_service


namespace map_service
{

namespace srv
{

namespace builder
{

class Init_PointRequest_Response_message
{
public:
  Init_PointRequest_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_service::srv::PointRequest_Response message(::map_service::srv::PointRequest_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_service::srv::PointRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_service::srv::PointRequest_Response>()
{
  return map_service::srv::builder::Init_PointRequest_Response_message();
}

}  // namespace map_service

#endif  // MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__BUILDER_HPP_
