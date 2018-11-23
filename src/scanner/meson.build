scanner_impl = files('scanner.c')
scanner_def = files('scanner.l')

flex = find_program('flex')

# run `flex -t` to pipe the output to stdout, which is captured by supplying
# the capture flag to `configure_file`
scanner_source = configure_file(
    input: scanner_def,
    output: 'scanner.yy.c',
    capture: true,
    command: [flex, '-t', scanner_def])

project_sources += scanner_impl
project_sources += scanner_source

scanner_lib = library('scanner',
    scanner_impl,
    scanner_source,
    include_directories: inc)
