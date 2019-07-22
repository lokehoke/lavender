#pragma once

extern "C"
{

typedef struct lvr_plugin_store_i lvr_plugin_store_i;

} // extern "C"

void plugin_store_init_impl();
void plugin_store_finalize_impl();
lvr_plugin_store_i* get_plugin_store_impl();
