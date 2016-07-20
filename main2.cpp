#include <iostream>
#include "SocketClient.h"
#include "SocketConnection.h"
#include <string.h>
#include <unistd.h>
#include <memory>
#include <thread>
using namespace std;

int main()
{
   SocketClient client{ "localhost", "2048"};
   unique_ptr<Socket> connectedSock;
   if ( client.connect(connectedSock) )
   {
      SocketConnection connection{ std::move(connectedSock) };
      connection.write( (char*)"hello world", 12 );
   }
   return 0;
}

