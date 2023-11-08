// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_service:srv/PointRequest.idl
// generated code does not contain a copyright notice
#include "map_service/srv/detail/point_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `lat`
// Member `lng`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
map_service__srv__PointRequest_Request__init(map_service__srv__PointRequest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // lat
  if (!rosidl_runtime_c__double__Sequence__init(&msg->lat, 0)) {
    map_service__srv__PointRequest_Request__fini(msg);
    return false;
  }
  // lng
  if (!rosidl_runtime_c__double__Sequence__init(&msg->lng, 0)) {
    map_service__srv__PointRequest_Request__fini(msg);
    return false;
  }
  return true;
}

void
map_service__srv__PointRequest_Request__fini(map_service__srv__PointRequest_Request * msg)
{
  if (!msg) {
    return;
  }
  // lat
  rosidl_runtime_c__double__Sequence__fini(&msg->lat);
  // lng
  rosidl_runtime_c__double__Sequence__fini(&msg->lng);
}

bool
map_service__srv__PointRequest_Request__are_equal(const map_service__srv__PointRequest_Request * lhs, const map_service__srv__PointRequest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lat
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->lat), &(rhs->lat)))
  {
    return false;
  }
  // lng
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->lng), &(rhs->lng)))
  {
    return false;
  }
  return true;
}

bool
map_service__srv__PointRequest_Request__copy(
  const map_service__srv__PointRequest_Request * input,
  map_service__srv__PointRequest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // lat
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->lat), &(output->lat)))
  {
    return false;
  }
  // lng
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->lng), &(output->lng)))
  {
    return false;
  }
  return true;
}

map_service__srv__PointRequest_Request *
map_service__srv__PointRequest_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Request * msg = (map_service__srv__PointRequest_Request *)allocator.allocate(sizeof(map_service__srv__PointRequest_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_service__srv__PointRequest_Request));
  bool success = map_service__srv__PointRequest_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_service__srv__PointRequest_Request__destroy(map_service__srv__PointRequest_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_service__srv__PointRequest_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_service__srv__PointRequest_Request__Sequence__init(map_service__srv__PointRequest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Request * data = NULL;

  if (size) {
    data = (map_service__srv__PointRequest_Request *)allocator.zero_allocate(size, sizeof(map_service__srv__PointRequest_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_service__srv__PointRequest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_service__srv__PointRequest_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
map_service__srv__PointRequest_Request__Sequence__fini(map_service__srv__PointRequest_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      map_service__srv__PointRequest_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

map_service__srv__PointRequest_Request__Sequence *
map_service__srv__PointRequest_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Request__Sequence * array = (map_service__srv__PointRequest_Request__Sequence *)allocator.allocate(sizeof(map_service__srv__PointRequest_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_service__srv__PointRequest_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_service__srv__PointRequest_Request__Sequence__destroy(map_service__srv__PointRequest_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_service__srv__PointRequest_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_service__srv__PointRequest_Request__Sequence__are_equal(const map_service__srv__PointRequest_Request__Sequence * lhs, const map_service__srv__PointRequest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_service__srv__PointRequest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_service__srv__PointRequest_Request__Sequence__copy(
  const map_service__srv__PointRequest_Request__Sequence * input,
  map_service__srv__PointRequest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_service__srv__PointRequest_Request);
    map_service__srv__PointRequest_Request * data =
      (map_service__srv__PointRequest_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_service__srv__PointRequest_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          map_service__srv__PointRequest_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_service__srv__PointRequest_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
map_service__srv__PointRequest_Response__init(map_service__srv__PointRequest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    map_service__srv__PointRequest_Response__fini(msg);
    return false;
  }
  return true;
}

void
map_service__srv__PointRequest_Response__fini(map_service__srv__PointRequest_Response * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
map_service__srv__PointRequest_Response__are_equal(const map_service__srv__PointRequest_Response * lhs, const map_service__srv__PointRequest_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
map_service__srv__PointRequest_Response__copy(
  const map_service__srv__PointRequest_Response * input,
  map_service__srv__PointRequest_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

map_service__srv__PointRequest_Response *
map_service__srv__PointRequest_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Response * msg = (map_service__srv__PointRequest_Response *)allocator.allocate(sizeof(map_service__srv__PointRequest_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_service__srv__PointRequest_Response));
  bool success = map_service__srv__PointRequest_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_service__srv__PointRequest_Response__destroy(map_service__srv__PointRequest_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_service__srv__PointRequest_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_service__srv__PointRequest_Response__Sequence__init(map_service__srv__PointRequest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Response * data = NULL;

  if (size) {
    data = (map_service__srv__PointRequest_Response *)allocator.zero_allocate(size, sizeof(map_service__srv__PointRequest_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_service__srv__PointRequest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_service__srv__PointRequest_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
map_service__srv__PointRequest_Response__Sequence__fini(map_service__srv__PointRequest_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      map_service__srv__PointRequest_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

map_service__srv__PointRequest_Response__Sequence *
map_service__srv__PointRequest_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_service__srv__PointRequest_Response__Sequence * array = (map_service__srv__PointRequest_Response__Sequence *)allocator.allocate(sizeof(map_service__srv__PointRequest_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_service__srv__PointRequest_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_service__srv__PointRequest_Response__Sequence__destroy(map_service__srv__PointRequest_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_service__srv__PointRequest_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_service__srv__PointRequest_Response__Sequence__are_equal(const map_service__srv__PointRequest_Response__Sequence * lhs, const map_service__srv__PointRequest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_service__srv__PointRequest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_service__srv__PointRequest_Response__Sequence__copy(
  const map_service__srv__PointRequest_Response__Sequence * input,
  map_service__srv__PointRequest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_service__srv__PointRequest_Response);
    map_service__srv__PointRequest_Response * data =
      (map_service__srv__PointRequest_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_service__srv__PointRequest_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          map_service__srv__PointRequest_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_service__srv__PointRequest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
