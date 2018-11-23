docs_config = configuration_data()
docs_config.set('TOP_SRCDIR', meson.source_root())
docs_config.set('TOP_BUILDDIR', meson.build_root())
docs_config.set('OUTPUT_DIR', join_paths(meson.build_root(), 'docs'))
docs_config.set('README_PATH', join_paths(meson.source_root(), 'README.md'))
docs_config.set('VERSION', meson.project_version())
docs_config.set('PROJECT_NAME', meson.project_name())

doxyfile = configure_file(
    input: 'Doxyfile.in',
    output: 'Doxyfile',
    configuration: docs_config,
    install: false)

doxygen = find_program('doxygen')

doc_target = run_target('doc', command: [doxygen, doxyfile])
