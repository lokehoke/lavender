#pragma once

#include "foundation/platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_plugin_store_i lvr_plugin_store_i;

LVR_API extern void lvr_core_init();
LVR_API extern void lvr_core_finalize();

LVR_API extern lvr_plugin_store_i* lvr_get_plugin_store();

#ifdef __cplusplus
}
#endif
