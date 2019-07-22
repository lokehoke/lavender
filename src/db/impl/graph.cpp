#include "db/impl/graph.hpp"

#include "db/graph.h"
#include "db/node.h" 

#include "foundation/uuid_operators.hpp"

#include <cstring>


void create_node(lvr_graph_t* inst, const char* node_impl_name)
{
    const auto plugin_store = inst->m_context->m_plugin_store;
    const auto logger = inst->m_context->m_logger;

    // const auto interface = plugin_store->lvr_query_interface_implementation(
    //     LVR_NODE_INTERFACE_NAME,
    //     node_impl_name);

    // if (!interface)
    // {
    //     logger->lvr_log(lvr_severity_panic, "Could not find interface implementation.");
    //     return;
    // }

    lvr_node_instance_t instance;
    //instance.m_interface = reinterpret_cast<const lvr_node_i* const>(interface);

    const auto num_input_attrs = instance.m_interface->m_num_input_attrs;
    const auto num_output_attrs = instance.m_interface->m_num_output_attrs;

    instance.m_input_attr_refs = new lvr_name_uuid_pair_t[num_input_attrs];
    instance.m_output_attr_refs = new lvr_name_uuid_pair_t[num_output_attrs];

    for (uint32_t idx = 0; idx < num_input_attrs; ++idx)
    {
        //
        //  create attributes here.
        //
    }

    for (uint32_t idx = 0; idx < num_output_attrs; ++idx)
    {
        //
        //  create attributes here.
        //
    }

    //
    // - generate UUIDs
    //

    inst->m_nodes.emplace(lvr_uuid_t {}, instance);
}


void destroy_node(lvr_graph_t* inst, lvr_uuid_t node)
{
    inst->m_nodes.erase(node);
}
 
// void (*connect_nodes)(
//     lvr_uuid_t from_node,
//     const char* from_attribute_name,
//     lvr_uuid_t to_node,
//     const char* to_attribute_name);

lvr_graph_i* create_graph_impl(const graph_context_t* ctx)
{
    auto interface = new lvr_graph_i;
    memset(interface, 0, sizeof(lvr_graph_i));

    auto instance = new lvr_graph_t(ctx);

    interface->m_instance = instance;
    interface->create_node = create_node;
    interface->destroy_node = destroy_node;

    return interface; 
}

void destroy_graph_impl(const graph_context_t* ctx, lvr_graph_i* graph)
{
    delete graph;
}
