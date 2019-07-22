#pragma once

#include "foundation/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// Specifies how value pointer should be interpreted (see ``lvr_attribute_t``).
typedef enum lvr_value_attribute_flag_t : uint16_t
{
    /// Value pointer is 32 bit signed integer.
    lvr_attribute_type_int32        = 0x0,

    /// Value pointer is 32 bit float.
    lvr_attribute_type_float        = 0x1,

    /// Value is UTF-8 null-terminated c string pointer (aka ``char*``).
    lvr_attribute_type_string       = 0x2,

    /// Value is ``lvr_uuid_t`` pointer.
    lvr_attribute_type_uuid         = 0x4,

    /// Value is an attribute schema pointer.
    lvr_attribute_type_schema       = 0x8
} lvr_value_attribute_flag_t;


///
/// Attribute is either a concrete value or a reference
/// to another attribute (uuid).
///
typedef struct lvr_attribute_t
{
    lvr_value_attribute_flag_t  m_attr_type_flag;
    void*                       m_value;
} lvr_attribute_t;


#ifdef __cplusplus
}
#endif
