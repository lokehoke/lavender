#pragma once

#include "foundation/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_plugin_store_i
{
    void (*lvr_add_module)(
        const char* interface_name,
        const void* interface);

    void (*lvr_add_extension)(
        const char* extension_name,
        const char* interface_name,
        const void* interface);

    const void* (*lvr_get_module)(const char* interface_name);
    
    const void* (*lvr_get_extension)(
        const char* extension_name,
        const char* interface_name);

} lvr_plugin_store_i;

#ifdef __cplusplus
}
#endif
