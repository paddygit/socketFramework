#include <unistd.h>
#include <cstring>
#include "UnixSocket.h"

/*..............................................................................
 * @brief ~Socket
 *
 * Input Parameters:
 *    @param: 
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
Socket::~Socket (  )
{
}
/*..............................................................................
 * @brief StreamSocket
 *
 * Input Parameters:
 *    @param:  parameters
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
StreamSocket::StreamSocket( ): StreamSocket( AF_INET, SOCK_STREAM, 0 )
{
}

/*..............................................................................
 * @brief StreamSocket
 *
 * Input Parameters:
 *    @param: 
 *        family
 *        type
 *        protocol
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
StreamSocket::StreamSocket ( int family, int type, int protocol )
{
   mSockHandle = socket(family, type, protocol);
}

/*..............................................................................
 * @brief StreamSocket
 *
 * Input Parameters:
 *    @param:  parameters
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
 StreamSocket::StreamSocket( int sockFD ): Socket( sockFD )
{
}
/*..............................................................................
 * @brief ~StreamSocket
 *
 * Input Parameters:
 *    @param:  parameters
 * Return Value:
 *    @returns 
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
 StreamSocket::~StreamSocket( )
{
   if ( -1 != mSockHandle )
   {
      //close( mSockHandle );
   }
}

/*..............................................................................
 * @brief setPortNumber
 *
 * Input Parameters:
 *    @param: 
 *        intportNumber
 * Return Value:
 *    @returns bool
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
void StreamSocket::setPortNumber ( unsigned int portNumber )
{
   mSockHandle = socket(AF_INET, SOCK_STREAM, 0 );
   struct sockaddr_in serverAddr;
   memset( reinterpret_cast<char*>(&serverAddr), 0, 
         sizeof( serverAddr) );

   serverAddr.sin_port = htons(portNumber);
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_addr.s_addr = INADDR_ANY;

    ::bind( mSockHandle, (sockaddr*)&serverAddr, sizeof(serverAddr) );
}

