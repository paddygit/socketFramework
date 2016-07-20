#include <errno.h>
#include "SocketClient.h"
#include <sys/socket.h>
#include <cstring>
#include <netdb.h>
#include <iostream>
using namespace std;

/*..............................................................................
 * @brief SocketClient
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
SocketClient::SocketClient (  ): mSocketHandle( new StreamSocket{} )
{
}

/*..............................................................................
 * @brief SocketClient
 *
 * Input Parameters:
 *    @param: 
 *        serverAddress
 *        portNumber
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
SocketClient::SocketClient ( string serverAddress, string portNumber ):
   mSocketHandle( new StreamSocket{} ),
   mServerAddress( serverAddress ),
   mPortNumber( portNumber )
{
}

/*..............................................................................
 * @brief ~SocketClient
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
SocketClient::~SocketClient (  )
{
}
/*..............................................................................
 * @brief setServerAddress
 *
 * Input Parameters:
 *    @param: char* serverAddress
 * Return Value:
 *    @returns void
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
void SocketClient::setServerAddress ( char* serverAddress )
{
   mServerAddress = serverAddress;
   return ;/*void*/
}

/*..............................................................................
 * @brief setPortNumber
 *
 * Input Parameters:
 *    @param: char* portNumber
 * Return Value:
 *    @returns void
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
void SocketClient::setPortNumber ( char* portNumber )
{
   mPortNumber = portNumber;
   return ;/*void*/
}

/*..............................................................................
 * @brief connect
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns bool
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
bool SocketClient::connect ( unique_ptr<Socket>& connectedSock )
{
   bool success = false;
   do
   {
      struct addrinfo* addrInfo,hints;
      memset(&hints, 0, sizeof (addrinfo));
      hints.ai_family = AF_UNSPEC; // use AF_INET6 to force IPv6
      hints.ai_socktype = SOCK_STREAM;
      if( 0 > getaddrinfo( mServerAddress.c_str(), mPortNumber.c_str(),
            &hints, &addrInfo ))
         break;

      for( auto ai = addrInfo; ai != nullptr; ai = ai->ai_next )
      {
         auto sock = unique_ptr<Socket>{ 
            new StreamSocket{ ai->ai_family, ai->ai_socktype, ai->ai_protocol } };
         if( 0 < *sock )
         {
            if( 0 <= ::connect( *sock, ai->ai_addr, ai->ai_addrlen))
            {
               cout<<"socket moved"<<endl;
               connectedSock = std::move( sock );
               success = true;
               break;
            }
         }
      }
   }
   while(0);

   return success;/*bool*/
}

