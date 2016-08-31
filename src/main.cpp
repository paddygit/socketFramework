#include <iostream>
#include "SocketServer.h"
#include "ServerInterface.h"
#include "SocketConnection.h"
#include "InputOutputInterface.h"
#include <unistd.h>
#include <thread>
using namespace std;

int main()
{
   UnixSocketServer sockServer;
   sockServer.bind( 2048 );
   sockServer.listen();
   unique_ptr<Socket> connectedSock;
   cout<<"test"<<endl;
   if ( sockServer.accept(connectedSock) )
   {
      cout<<"test"<<endl;
      SocketConnection connection{ std::move(connectedSock) };
      char buffer[4098] = { '\0' };
      connection.read( buffer, 4098 );
      cout<<buffer;
   }
   return 0;
}

