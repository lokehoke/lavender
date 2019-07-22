#pragma once

#include "foundation/platform.h"

#define LVR_DATABASE_MODULE_NAME "lvr_database_module"
#define LVR_DATABASE_MODULE_INTERFACE_NAME "lvr_database_module_i"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_plugin_store_i lvr_plugin_store_i;
typedef struct lvr_graph_i lvr_graph_i; 

struct lvr_database_module_i
{
    lvr_graph_i* (*create_graph)();
    void (*destroy_graph)(lvr_graph_i* graph);
};

LVR_API extern void lvr_database_module_init(const lvr_plugin_store_i* plugin_store);

#ifdef __cplusplus
}
#endif
