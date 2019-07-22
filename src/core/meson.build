core_src = [
    'impl/core.cpp',
    'impl/plugin_store.cpp',
    'impl/logger.cpp'
]

core_python_src = [
    'python_binding/module.cpp'
]

core = library(
    'core',
    core_src,
    include_directories: root_include_dir
)

core_dep = declare_dependency(link_with: core)

core_python = library(
    '_core',
    core_python_src,
    include_directories: root_include_dir,
    dependencies: [core_dep, python_dep],
    name_prefix: ''
)