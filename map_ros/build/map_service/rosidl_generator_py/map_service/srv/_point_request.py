# generated from rosidl_generator_py/resource/_idl.py.em
# with input from map_service:srv/PointRequest.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'lat'
# Member 'lng'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PointRequest_Request(type):
    """Metaclass of message 'PointRequest_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('map_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'map_service.srv.PointRequest_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__point_request__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__point_request__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__point_request__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__point_request__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__point_request__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PointRequest_Request(metaclass=Metaclass_PointRequest_Request):
    """Message class 'PointRequest_Request'."""

    __slots__ = [
        '_lat',
        '_lng',
    ]

    _fields_and_field_types = {
        'lat': 'sequence<double>',
        'lng': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.lat = array.array('d', kwargs.get('lat', []))
        self.lng = array.array('d', kwargs.get('lng', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.lat != other.lat:
            return False
        if self.lng != other.lng:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'lat' array.array() must have the type code of 'd'"
            self._lat = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'lat' field must be a set or sequence and each value of type 'float'"
        self._lat = array.array('d', value)

    @property
    def lng(self):
        """Message field 'lng'."""
        return self._lng

    @lng.setter
    def lng(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'lng' array.array() must have the type code of 'd'"
            self._lng = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'lng' field must be a set or sequence and each value of type 'float'"
        self._lng = array.array('d', value)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_PointRequest_Response(type):
    """Metaclass of message 'PointRequest_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('map_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'map_service.srv.PointRequest_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__point_request__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__point_request__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__point_request__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__point_request__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__point_request__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PointRequest_Response(metaclass=Metaclass_PointRequest_Response):
    """Message class 'PointRequest_Response'."""

    __slots__ = [
        '_message',
    ]

    _fields_and_field_types = {
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_PointRequest(type):
    """Metaclass of service 'PointRequest'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('map_service')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'map_service.srv.PointRequest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__point_request

            from map_service.srv import _point_request
            if _point_request.Metaclass_PointRequest_Request._TYPE_SUPPORT is None:
                _point_request.Metaclass_PointRequest_Request.__import_type_support__()
            if _point_request.Metaclass_PointRequest_Response._TYPE_SUPPORT is None:
                _point_request.Metaclass_PointRequest_Response.__import_type_support__()


class PointRequest(metaclass=Metaclass_PointRequest):
    from map_service.srv._point_request import PointRequest_Request as Request
    from map_service.srv._point_request import PointRequest_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
