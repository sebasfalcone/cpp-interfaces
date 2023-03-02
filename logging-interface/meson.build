# logging-interface project

project(
  'logging_interface',
  'cpp',
  version : '1.0.0',
  default_options : [
    'warning_level=3', 
    'cpp_std=c++17'
  ]
)

project_description = 'This project is a wrapper arround different logging libraries'

project_headers = [
]

project_sources = [
  'src/main.cpp'
]

test_sources = [
  'tests/src/main.cpp',
]

build_args = [
]

# Dependencies
fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')

# ======
# Target
# ======

public_headers = include_directories('include')

build_args += [
  '-DPROJECT_NAME=' + meson.project_name(),
  '-DPROJECT_VERSION=' + meson.project_version(),
]

# Only make public interfaces visible
if target_machine.system() == 'windows' or target_machine.system() == 'cygwin'
  build_args += '-DMYLIB_PUBLIC="__declspec(dllexport)"'
else
  build_args += '-DMYLIB_PUBLIC=__attribute__((visibility("default")))'
endif

project_target = shared_library(
  meson.project_name(),
  project_sources,
  install : true,
  c_args : build_args,
  gnu_symbol_visibility : 'hidden',
  include_directories : public_headers,
  dependencies: [
    fmt_dep
  ]
)

# =======
# Project
# =======

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
  include_directories: public_headers,
  link_with : project_target
)

set_variable(meson.project_name() + '_dep', project_dep)

# Make this library usable from the system's package manager.
install_headers(project_headers, subdir : meson.project_name())

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  subdirs : meson.project_name(),
  libraries : project_target,
)


# ==========
# Unit Tests
# ==========

if not meson.is_subproject()
  
  add_languages('cpp') 
  subdir('tests')

  test(
    'tests',
    executable(
      'run_tests',
      files(test_sources),
      dependencies : [
        project_dep, 
        test_dep
      ],
      install : false
    )
  )
endif
