db_src = [
    'impl/db_module.cpp',
    'impl/graph.cpp'
]

db_python_src = [
    'python_binding/module.cpp'
]

database = library(
    'database',
    db_src,
    include_directories: root_include_dir
)

database_dep = declare_dependency(link_with: database)

graph_python = library(
    '_database',
    db_python_src,
    include_directories: root_include_dir,
    dependencies: [database_dep, python_dep],
    name_prefix: ''
)
