cmake_minimum_required( VERSION 2.6 )

project( SocketServer )

set( CMAKE_CXX_FLAGS "-std=c++1y -pthread -Wl,--no-as-needed")

set (SOURCE  SocketServer.cpp SocketConnection.cpp UnixSocket.cpp main.cpp )
set (SOURCE2  SocketClient.cpp SocketConnection.cpp UnixSocket.cpp main2.cpp )


add_executable( server ${SOURCE}) 
add_executable( client ${SOURCE2}) 

#target_link_libraries( audiorec asound )

install (TARGETS server DESTINATION bin)
install (TARGETS client DESTINATION bin)

