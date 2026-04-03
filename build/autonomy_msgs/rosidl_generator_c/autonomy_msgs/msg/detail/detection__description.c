// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from autonomy_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

#include "autonomy_msgs/msg/detail/detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_autonomy_msgs
const rosidl_type_hash_t *
autonomy_msgs__msg__Detection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x26, 0x19, 0x20, 0x01, 0x5c, 0xb6, 0x00, 0x42,
      0x0d, 0xa4, 0x2a, 0x93, 0x66, 0x4b, 0xe3, 0x79,
      0xfa, 0xf9, 0x46, 0x2e, 0x8b, 0x5a, 0x02, 0x00,
      0x9f, 0xaa, 0xd0, 0xd3, 0xd2, 0x3d, 0x1d, 0x5e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char autonomy_msgs__msg__Detection__TYPE_NAME[] = "autonomy_msgs/msg/Detection";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char autonomy_msgs__msg__Detection__FIELD_NAME__position[] = "position";
static char autonomy_msgs__msg__Detection__FIELD_NAME__distance[] = "distance";
static char autonomy_msgs__msg__Detection__FIELD_NAME__angle[] = "angle";
static char autonomy_msgs__msg__Detection__FIELD_NAME__size_x[] = "size_x";
static char autonomy_msgs__msg__Detection__FIELD_NAME__size_y[] = "size_y";
static char autonomy_msgs__msg__Detection__FIELD_NAME__label[] = "label";
static char autonomy_msgs__msg__Detection__FIELD_NAME__confidence[] = "confidence";

static rosidl_runtime_c__type_description__Field autonomy_msgs__msg__Detection__FIELDS[] = {
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__angle, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__size_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__size_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__label, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {autonomy_msgs__msg__Detection__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription autonomy_msgs__msg__Detection__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
autonomy_msgs__msg__Detection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {autonomy_msgs__msg__Detection__TYPE_NAME, 27, 27},
      {autonomy_msgs__msg__Detection__FIELDS, 7, 7},
    },
    {autonomy_msgs__msg__Detection__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "geometry_msgs/Point position\n"
  "float32 distance\n"
  "float32 angle\n"
  "float32 size_x\n"
  "float32 size_y\n"
  "string label\n"
  "float32 confidence";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
autonomy_msgs__msg__Detection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {autonomy_msgs__msg__Detection__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 121, 121},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
autonomy_msgs__msg__Detection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *autonomy_msgs__msg__Detection__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
