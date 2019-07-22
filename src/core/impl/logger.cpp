#include "core/impl/logger.hpp"

#include "core/logger.h"
#include "core/plugin_store.h"

#include "foundation/types.h"

#include <iostream>
#include <vector>

static lvr_logger_i* g_logger = nullptr;
std::vector<lvr_logger_sink_i*> g_sinks;

void log_stderr(lvr_severity_t severity, const char* message)
{
    std::cerr << message << std::endl;
}

void logger_init_impl(const lvr_plugin_store_i* plugin_store)
{
    g_logger = new lvr_logger_i;

    // uint32_t n_sinks = 0u;
    // plugin_store->lvr_query_interface_implementations(
    //     LVR_LOGGER_SINK_INTERFACE_NAME,
    //     &n_sinks,
    //     nullptr);
    
    log_stderr(
        lvr_severity_panic,
        "No logger sinks found. Using stderr for logging.");

    g_logger->lvr_log = log_stderr; 

    plugin_store->lvr_add_module(
        LVR_LOGGER_INTERFACE_NAME,
        g_logger);
}

void logger_finalize_impl()
{
    delete g_logger;
}
