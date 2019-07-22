#include "core/core.h"
#include "core/plugin_store.h"

#include "foundation/platform.h"

#include <Python.h>

PyObject* core_init(PyObject*, PyObject*)
{
    lvr_core_init();

    Py_INCREF(Py_None);
    return Py_None;
}

PyObject* get_plugin_store(PyObject* self, PyObject*)
{
    const auto plugin_store = lvr_get_plugin_store();

    const auto plugin_store_capsule = PyCapsule_New(
        static_cast<void*>(plugin_store),
        "ModuleStore",
        [](PyObject*){});

    if (!plugin_store_capsule)
    {
        return nullptr;
    }

    return plugin_store_capsule;
}

static PyMethodDef g_core_methods_definition[]
{
    {"init", core_init, METH_NOARGS, nullptr},
    {"get_plugin_store", get_plugin_store, METH_NOARGS, nullptr},
    {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef g_core_module_definition
{
    PyModuleDef_HEAD_INIT,
    "core",
    nullptr,
    -1,
    g_core_methods_definition
};

extern "C"
{

LVR_API extern PyObject* PyInit__core()
{
    PyObject* core_python_module = PyModule_Create(&g_core_module_definition);

    if (!core_python_module)
    {
        return nullptr;
    }

    return core_python_module;    
}

} // extern "C"
