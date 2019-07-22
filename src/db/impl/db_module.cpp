#include "db/impl/graph.hpp"

#include "db/db_module.h"
#include "db/graph.h"

#include "core/plugin_store.h"
#include "core/logger.h"

static graph_context_t* g_graph_context;

lvr_graph_i* create_graph()
{
    return create_graph_impl(g_graph_context);
}

void destroy_graph(lvr_graph_i* graph)
{
    destroy_graph_impl(g_graph_context, graph);
}

extern void lvr_database_module_init(const lvr_plugin_store_i* plugin_store)
{
    const auto module = new lvr_database_module_i;
    module->create_graph = create_graph;
    module->destroy_graph = destroy_graph;

    plugin_store->lvr_add_module(
        LVR_DATABASE_MODULE_INTERFACE_NAME,
        module);

    const auto logger = reinterpret_cast<const lvr_logger_i*>(
        plugin_store->lvr_get_module(LVR_LOGGER_INTERFACE_NAME));

    g_graph_context = new graph_context_t;
    g_graph_context->m_logger = logger;
    g_graph_context->m_plugin_store = plugin_store;
    
    logger->lvr_log(lvr_severity_panic, "Database module initialized!");
}
