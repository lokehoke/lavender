#pragma once

#include "foundation/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_graph_t lvr_graph_t;

typedef struct lvr_graph_i
{
    lvr_graph_t* m_instance;

    void (*create_node)(lvr_graph_t* inst, const char* node_impl_name);
    void (*destroy_node)(lvr_graph_t* inst, lvr_uuid_t node);

    void (*connect_nodes)(
        const lvr_graph_t* inst,
        lvr_uuid_t from_node,
        const char* from_attribute_name,
        lvr_uuid_t to_node,
        const char* to_attribute_name);
} lvr_graph_i; 

#ifdef __cplusplus
}
#endif
