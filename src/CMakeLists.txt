# Build the printer.

include_directories( ${libEMF_SOURCE_DIR}/include )

add_executable( printemf printemf.c )

target_link_libraries( printemf emf )

install( TARGETS printemf
         RUNTIME DESTINATION bin )
