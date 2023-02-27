# Builds google test as a dependency called "test_depdepencies".

# get the shared directory of the project
shared_dir = './../../shared'

# Gtest
gtest_dir = join_paths(shared_dir, 'googletest/googletest')
gtest_include_dir = join_paths(gtest_dir, 'include')

include_directories(gtest_include_dir, is_system : true)

libgtest = static_library(
  'gtest',
  cpp_args : ['-w'],
  include_directories : [include_directories(gtest_dir), gtest_include_dir],
  sources : [
    join_paths(gtest_dir, 'src', 'gtest-all.cc'),
    join_paths(gtest_dir, 'src', 'gtest_main.cc')
  ]
)

test_depdepencies = declare_dependency(
  dependencies : dependency('threads'),
  include_directories : gtest_include_dir,
  link_with : libgtest
)
