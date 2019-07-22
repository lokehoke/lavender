#include "core/impl/plugin_store.hpp"
#include "core/impl/logger.hpp"

#include "core/plugin_store.h"
#include "core/core.h"
#include "core/logger.h"

void lvr_core_init()
{
    plugin_store_init_impl();

    const auto plugin_store = lvr_get_plugin_store();

    logger_init_impl(plugin_store);

    const auto logger = reinterpret_cast<const lvr_logger_i*>(
        plugin_store->lvr_get_module(LVR_LOGGER_INTERFACE_NAME));
    
    logger->lvr_log(lvr_severity_panic, "Lavender core initialized!");
}

void lvr_core_finalize()
{
    plugin_store_finalize_impl();
    logger_finalize_impl();
}

lvr_plugin_store_i* lvr_get_plugin_store()
{
    return get_plugin_store_impl();
}
