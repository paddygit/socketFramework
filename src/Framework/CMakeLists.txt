cmake_minimum_required( VERSION 2.6 )

set( CMAKE_CXX_FLAGS "-std=c++11 -g -pthread -Wl,--no-as-needed")

set( SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnixSocket.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SocketServer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SocketConnection.cpp
   PARENT_SCOPE
   )

set( SOURCE2
   ${SOURCE2}
   ${CMAKE_CURRENT_SOURCE_DIR}/UnixSocket.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SocketClient.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/SocketConnection.cpp
   PARENT_SCOPE
   )

