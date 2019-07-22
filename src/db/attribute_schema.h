#pragma once

#include "foundation/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

///
/// Attribute shcema is a type of attribute for arbitrary
/// value types. It provides interface to access the value
/// alongside the value itself.
///
typedef struct lvr_attribute_schema_t
{
    const char* m_interface_name;
    const void* m_interface;
    const void* m_inst;
} lvr_attribute_schema_t;

#ifdef __cplusplus
}
#endif
