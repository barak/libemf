# Not really needed, but for better consonance with autoconf.  Note
# that the config.h.in file is different for CMake.
project( config )

configure_file( config.cmake.h.in config.h )
