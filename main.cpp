#include <iostream>
#include "SocketServer.h"
#include "SocketConnection.h"
#include <unistd.h>
#include <thread>
using namespace std;

int main()
{
   UnixSocketServer sockServer;
   sockServer.bind( 2048 );
   sockServer.listen();
   unique_ptr<Socket> connectedSock;
   if ( sockServer.accept(connectedSock) )
   {
      SocketConnection connection{ std::move(connectedSock) };
      char buffer[256] = { '\0' };
      connection.read( buffer, 255 );
      cout<<buffer;
   }
   return 0;
}

