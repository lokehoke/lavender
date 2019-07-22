#include "core/impl/plugin_store.hpp"

#include "core/plugin_store.h"

#include <cassert>
#include <cstring>
#include <map>
#include <string>

static std::map<std::string, const void*> g_modules_map;
static std::multimap<std::string, const void*> g_extensions_map;

static lvr_plugin_store_i* g_plugin_store = nullptr;

//
//  lvr_plugin_store_i methods implementation.
//

void add_module(const char* interface_name, const void* interface)
{
    const auto [itr, res] = g_modules_map.emplace(interface_name, interface);

    if (!res)
    {
        return;
    }
}

const void* get_module(const char* module_name)
{
    const auto module_itr = g_modules_map.find(module_name);
    if (module_itr != g_modules_map.end())
    {
        return module_itr->second;
    }

    return nullptr;
}

//
//  Internal functions implementation.
//

void plugin_store_init_impl()
{
    g_plugin_store = new lvr_plugin_store_i;
    g_plugin_store->lvr_add_module = add_module;
    g_plugin_store->lvr_get_module = get_module;
    // TODO
}

void plugin_store_finalize_impl()
{
    delete g_plugin_store;
}

lvr_plugin_store_i* get_plugin_store_impl()
{
    assert(g_plugin_store);
    return g_plugin_store;
}
