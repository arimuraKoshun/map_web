// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice

#ifndef MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_HPP_
#define MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__map_service__srv__PointRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__map_service__srv__PointRequest_Request __declspec(deprecated)
#endif

namespace map_service
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PointRequest_Request_
{
  using Type = PointRequest_Request_<ContainerAllocator>;

  explicit PointRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PointRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _lat_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _lat_type lat;
  using _lng_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _lng_type lng;

  // setters for named parameter idiom
  Type & set__lat(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lng(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->lng = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_service::srv::PointRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_service::srv::PointRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_service::srv::PointRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_service::srv::PointRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_service__srv__PointRequest_Request
    std::shared_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_service__srv__PointRequest_Request
    std::shared_ptr<map_service::srv::PointRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointRequest_Request_ & other) const
  {
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lng != other.lng) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointRequest_Request_

// alias to use template instance with default allocator
using PointRequest_Request =
  map_service::srv::PointRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace map_service


#ifndef _WIN32
# define DEPRECATED__map_service__srv__PointRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__map_service__srv__PointRequest_Response __declspec(deprecated)
#endif

namespace map_service
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PointRequest_Response_
{
  using Type = PointRequest_Response_<ContainerAllocator>;

  explicit PointRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  explicit PointRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_service::srv::PointRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_service::srv::PointRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_service::srv::PointRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_service::srv::PointRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_service__srv__PointRequest_Response
    std::shared_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_service__srv__PointRequest_Response
    std::shared_ptr<map_service::srv::PointRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointRequest_Response_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointRequest_Response_

// alias to use template instance with default allocator
using PointRequest_Response =
  map_service::srv::PointRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace map_service

namespace map_service
{

namespace srv
{

struct PointRequest
{
  using Request = map_service::srv::PointRequest_Request;
  using Response = map_service::srv::PointRequest_Response;
};

}  // namespace srv

}  // namespace map_service

#endif  // MAP_SERVICE__SRV__DETAIL__POINT_REQUEST__STRUCT_HPP_
