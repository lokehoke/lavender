#include "db/db_module.h"

#include "core/plugin_store.h"

#include "foundation/platform.h"

#include <Python.h>

PyObject* database_module_init(PyObject*, PyObject* args)
{
    const auto plugin_store_capsule = PyTuple_GetItem(args, 0);

    if (!plugin_store_capsule)
    {
        return nullptr;
    }

    const void* plugin_store = PyCapsule_GetPointer(plugin_store_capsule, "ModuleStore");

    if (!plugin_store)
    {
        return nullptr;
    }

    lvr_database_module_init(reinterpret_cast<const lvr_plugin_store_i*>(plugin_store));

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef g_database_methods_definition[]
{
    {"init", database_module_init, METH_VARARGS, nullptr},
    {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef g_graph_module_definition
{
    PyModuleDef_HEAD_INIT,
    "database",
    nullptr,
    -1,
    g_database_methods_definition
};

extern "C"
{

LVR_API extern PyObject* PyInit__database()
{
    PyObject *database_python_module = nullptr;

    database_python_module = PyModule_Create(&g_graph_module_definition);

    if (!database_python_module)
    {
        return nullptr;
    }

    return database_python_module;    
}

} // extern "C"
