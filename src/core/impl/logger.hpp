#pragma once

extern "C"
{

typedef struct lvr_plugin_store_i lvr_plugin_store_i;

} // extern "C"

void logger_init_impl(const lvr_plugin_store_i* plugin_store);
void logger_finalize_impl();
