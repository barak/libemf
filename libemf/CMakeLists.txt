# Build the library.

include_directories( ${config_BINARY_DIR} ${libEMF_SOURCE_DIR}/include )

add_library( emf libemf.cpp )
