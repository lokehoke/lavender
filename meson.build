project('lavender', 'cpp', version: '0.1')


#
#   Global compile options.
#

add_project_arguments('-fvisibility=hidden', language: 'cpp')


#
#   Thirdparty dependencies.
#

gtest_dep = subproject('gtest').get_variable('gtest_dep')
tbb_dep = subproject('TBB').get_variable('tbb_dep')

python_dep = dependency('python3')

#
#   Build targets.
#

subdir('src')
