project('zeichma', 'c',
    version: '1.0',
    license: ['GPLv3'],
    default_options: ['warning_level=3'])

library_path = []
project_sources = []
project_header_files = []
project_test_sources = []

inc = [include_directories('include')]

subdir('include')
subdir('third_party')
subdir('src')

deps = [
#    meson.get_compiler('c').find_library('<local-third-party-lib>',
#        required: true,
#        dirs: library_path)
]

deps_lib = [
    scanner_lib,
]

project_bin = executable('zeichma',
    main_source,
    include_directories: inc,
    dependencies: deps,
    link_with: deps_lib)

#if get_option('enable-tests')
#    subdir('tests')
#endif
#if get_option('enable-benchmarks')
#    subdir('benchmarks')
#endif

subdir('docs')

# enable if .clang-format file is available
#configure_file(
#    input: '.clang-format',
#    output: '.clang-format',
#    configuration: configuration_data())
#run_target('format',
#    command: [
#        'clang-format',
#        '-i',
#        '--style=file',
#        project_sources,
#        project_header_files])
