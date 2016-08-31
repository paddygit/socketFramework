#include <unistd.h>
#include "SocketServer.h"
#include <cstring>
using namespace std;

/*..............................................................................
 * @brief UnixSocketServer
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
UnixSocketServer::UnixSocketServer (  )
{
   mSock = unique_ptr<Socket>{ new StreamSocket{} };
}

/*..............................................................................
 * @brief ~UnixSocketServer
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
UnixSocketServer::~UnixSocketServer (  )
{
}

/*..............................................................................
 * @brief bind
 *
 * Input Parameters:
 *    @param: 
 *        portNumber
 * Return Value:
 *    @returns bool
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
bool UnixSocketServer::bind ( unsigned int portNumber )
{
   struct sockaddr_in serverAddr;
   memset( reinterpret_cast<char*>(&serverAddr), 0, 
         sizeof( serverAddr) );

   serverAddr.sin_port = htons(portNumber);
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_addr.s_addr = INADDR_ANY;

   return ( 0 < ::bind( *mSock, (sockaddr*)&serverAddr, sizeof(serverAddr) ) )?
      true : false;
}

/*..............................................................................
 * @brief listen
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns bool
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
bool UnixSocketServer::listen ( )
{
   return ( 0 < ::listen( *mSock, 1 ))? true: false;
}

/*..............................................................................
 * @brief accept
 *
 * Input Parameters:
 *    @param: Socket&
 * Return Value:
 *    @returns bool
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
bool UnixSocketServer::accept (  unique_ptr<Socket>& socket )
{
   struct sockaddr_in clientAddr;
   bool success = false;
   memset( reinterpret_cast<char*>(&clientAddr), 0, sizeof( clientAddr ) );
   socklen_t len = sizeof( clientAddr );
   socket = unique_ptr<Socket>{ new StreamSocket {::accept( *mSock, (sockaddr*) &clientAddr, &len)}};
   if( *socket > 0 )
   {
      success = true;
   }
   return success;/*bool*/
}

