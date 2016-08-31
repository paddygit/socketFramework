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
      std::string myTestString = "from green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fienddddddddddddddfrom green to red our days pass by waiting for a sign to tell us why, are we dancing all alone, collect some stars to shine for you and start today there is only a few, a sign of times my fiend";
      connection.write( myTestString.c_str() , myTestString.length() );
   }
   return 0;
}

