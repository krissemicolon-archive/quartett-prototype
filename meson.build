project(
    'quartett',
    'c',
    version : '1.0.0',
    license : 'BSD3',
    default_options : [
      'c_std=c99',
      'buildtype=release',
      'default_library=shared',
      'optimization=2',
      'b_lto=false',
    ]
)

# Meson Wildcard Sources
c = run_command('scripts/meson_wildcard.sh', check: true)
sources = c.stdout().strip().split('\n')

# Flags etc
cflags = '-Wall'
macros = '-DVERSION="1.0.0"'
inc = include_directories('include')

executable( 
    meson.project_name(),
    sources,
    c_args: [cflags, macros],
    include_directories: inc
)
