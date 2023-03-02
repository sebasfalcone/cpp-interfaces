cc = meson.get_compiler('cpp')

# Dependencies
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

threads_dep =  cc.find_library('pthread', required : true)

# Builds gtest as a dependency called "test_dep".
gtest_lib = static_library(
  'gtest',
  dependencies : [
    threads_dep,
    gtest_dep
  ]
)

test_dep = declare_dependency(
  link_with : gtest_lib
)
