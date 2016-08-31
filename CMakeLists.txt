cmake_minimum_required( VERSION 2.6 )

project( SocketServer )

set( CMAKE_CXX_FLAGS "-std=c++11 -g -pthread -Wl,--no-as-needed")

find_path( SOCKET_INC sys/socket.h )
find_path( UNISTD unistd.h )

#ind_library( STDCPP stdc++ )

MESSAGE (STATUS "test value " ${UNISTD} )
MESSAGE (STATUS "socket library path" ${SOCKET} )

include_directories( "${SOCKET_INC}" "${UNISTD}" )
include_directories( 
   "${PROJECT_SOURCE_DIR}/src/Framework"
   "${PROJECT_SOURCE_DIR}/src/Interfaces"
    )

add_subdirectory( "${PROJECT_SOURCE_DIR}/src" )

add_executable( server ${SOURCE}) 
add_executable( client ${SOURCE2}) 

target_link_libraries( server )
target_link_libraries( client )

install (TARGETS server client
   DESTINATION bin)

