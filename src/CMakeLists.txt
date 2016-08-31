cmake_minimum_required( VERSION 2.6 )

set( CMAKE_CXX_FLAGS "-std=c++11 -g -pthread -Wl,--no-as-needed")

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/Framework )

set( SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   PARENT_SCOPE
   )

set( SOURCE2
   ${SOURCE2}
   ${CMAKE_CURRENT_SOURCE_DIR}/main2.cpp
   PARENT_SCOPE
   )
