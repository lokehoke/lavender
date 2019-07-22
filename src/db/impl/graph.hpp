#pragma once

#include "db/graph.h"
#include "db/attribute.h"
#include "db/node.h"

#include "core/logger.h"
#include "core/plugin_store.h"

#include "foundation/types.h"

#include <map>
#include <string>


struct graph_context_t
{
    const lvr_logger_i*         m_logger;
    const lvr_plugin_store_i*   m_plugin_store;
};

struct connection_t
{
    lvr_uuid_t                  m_from_node;
    std::string                 m_from_attr_name;
    lvr_uuid_t                  m_to_node;
    std::string                 m_to_attr_name;
};

struct lvr_graph_t
{
    using node_map_t = std::map<lvr_uuid_t, lvr_node_instance_t>;
    using attr_map_t = std::map<lvr_uuid_t, lvr_attribute_t>;

    lvr_graph_t(const graph_context_t* ctx)
      : m_context(ctx)
    {}
    
    node_map_t                  m_nodes;
    attr_map_t                  m_values;
    const graph_context_t*      m_context;
};

lvr_graph_i* create_graph_impl(const graph_context_t* ctx);
void destroy_graph_impl(const graph_context_t* ctx, lvr_graph_i* graph);
