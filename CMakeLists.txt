# Build scheme for libEMF

cmake_minimum_required( VERSION 3.10 )

project( libEMF )

# Our single option.
set( ENABLE_EDITING OFF CACHE BOOL
  "Enable the API function to print the contents of a metafile." )

add_subdirectory( config )

add_subdirectory( libemf )

if ( ENABLE_EDITING )
  add_subdirectory( src )
endif()

enable_testing()
add_subdirectory( tests )

install( DIRECTORY include/
         DESTINATION include
         FILES_MATCHING PATTERN "*.h" )
