# Build the library.

include_directories( ${config_BINARY_DIR} ${libEMF_SOURCE_DIR}/include )

add_library( emf libemf.cpp )

set_target_properties( emf PROPERTIES VERSION "1.0.0" )

install( TARGETS emf
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
 )
