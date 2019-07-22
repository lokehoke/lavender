#pragma once

#include "foundation/types.h"

#define LVR_NODE_INTERFACE_NAME "lvr_node_i"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_attribute_t lvr_attribute_t;
typedef struct lvr_node_i lvr_node_i;

typedef struct lvr_name_attr_pair_t
{
    const char*             m_name;
    const lvr_attribute_t*  m_attr;
} lvr_name_attr_pair_t;

typedef struct lvr_name_uuid_pair_t
{
    const char*             m_name;
    lvr_uuid_t              m_uuid;
} lvr_name_uuid_pair_t;


///
/// This structure stands out from ordinary
/// "interface" pattern used througout the codebase.
/// The reason is in different intent: while usual "interface"
/// instance types serve as opaque handles, ``lvr_node_instance_t``
/// is used as database container and is mutated directly by database module.
///
typedef struct lvr_node_instance_t
{
    const lvr_node_i*               m_interface;
    lvr_name_uuid_pair_t*           m_input_attr_refs;
    lvr_name_uuid_pair_t*           m_output_attr_refs;
} lvr_node_instance_t;


typedef struct lvr_node_i
{   
    /// Initial attributes express both attributes required and
    /// default values for those attributes.
    /// Attributes are copied on ``lvr_node_instance_t`` creation, so
    /// each name/attr pair is reflected as name/uuid pair in the instance 
    /// where uuid is the reference to the newly cloned attribute.
    /// @{
    const uint32_t                  m_num_input_attrs;
    const lvr_name_attr_pair_t*     m_initial_input_attrs;

    const uint32_t                  m_num_output_attrs;
    const lvr_name_attr_pair_t*     m_initial_output_attrs;
    /// @}
} lvr_node_i;


#ifdef __cplusplus
}
#endif
