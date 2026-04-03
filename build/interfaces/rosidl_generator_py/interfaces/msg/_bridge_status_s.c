// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interfaces:msg/BridgeStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "interfaces/msg/detail/bridge_status__struct.h"
#include "interfaces/msg/detail/bridge_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool interfaces__msg__bridge_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("interfaces.msg._bridge_status.BridgeStatus", full_classname_dest, 42) == 0);
  }
  interfaces__msg__BridgeStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // connected
    PyObject * field = PyObject_GetAttrString(_pymsg, "connected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->connected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // command_stream_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "command_stream_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->command_stream_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // tx_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "tx_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tx_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rx_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "rx_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rx_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // crc_error_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "crc_error_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->crc_error_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // timeout_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "timeout_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timeout_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->state, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interfaces__msg__bridge_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BridgeStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interfaces.msg._bridge_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BridgeStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interfaces__msg__BridgeStatus * ros_message = (interfaces__msg__BridgeStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // connected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->connected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "connected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // command_stream_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->command_stream_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "command_stream_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tx_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->tx_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tx_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rx_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rx_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rx_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // crc_error_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->crc_error_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "crc_error_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timeout_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->timeout_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timeout_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->state.data,
      strlen(ros_message->state.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
