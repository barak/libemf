# Do some light testing of the library.

project( tests )

include_directories( ${libEMF_SOURCE_DIR}/include )

add_executable( check1 check1.c )
target_link_libraries( check1 emf )
add_test( check1 ${tests_SOURCE_DIR}/docheck1.sh )

add_executable( check2 check2.c )
target_link_libraries( check2 emf )
add_test( check2 ${tests_SOURCE_DIR}/docheck2.sh )

add_executable( check3 check3.c )
target_link_libraries( check3 emf )
add_test( check3 ${tests_SOURCE_DIR}/docheck3.sh )

add_executable( check4 check4.c )
target_link_libraries( check4 emf )
#add_test( check4 ${tests_SOURCE_DIR}/docheck4.sh )

# For consonance with the automake test script:

set_tests_properties( check1 check2 check3 PROPERTIES
  ENVIRONMENT srcdir=${tests_SOURCE_DIR} )
