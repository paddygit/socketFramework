#include "SocketConnection.h"
#include <sys/poll.h>
#include <unistd.h>

/*..............................................................................
 * @brief read
 *
 * Input Parameters:
 *    @param: char* buffer, 
 *        bufferSize
 * Return Value:
 *    @returns size_t
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
size_t SocketConnection::read ( const char* buffer, size_t bufferSize )
{
   size_t bytesRead = 0;
   bytesRead = ::recv( *mSocket, (void*)buffer, bufferSize, 0 );
   if( 0 == bytesRead )
   {
      auto descriptors = new pollfd[1];
      descriptors[0].fd = *mSocket;
      descriptors[0].events = POLLPRI;
      if( 0 > poll( descriptors, 1, -1 ))
      {
         /// error
      }
      else
      {
         bytesRead = ::recv( *mSocket, (void*)buffer, bufferSize, 0 );
      }
      delete[] descriptors;
   }
   return bytesRead;/*size_t*/
}

/*..............................................................................
 * @brief write
 *
 * Input Parameters:
 *    @param: char* buffer, 
 *        bufferSize
 * Return Value:
 *    @returns size_t
 *
 * External methods/variables:
 *    @extern
 *............................................................................*/
size_t SocketConnection::write ( const char* buffer, size_t bufferSize )
{
   size_t bytesWritten = 0;
   auto startAddress = buffer;
   size_t totalBytesWritten = 0;
   do
   {
      auto bytesToSend = bufferSize - bytesWritten;
      startAddress += bytesWritten;
      bytesWritten  = ::send( *mSocket, startAddress, bytesToSend , 0);
      totalBytesWritten += bytesWritten;
   }
   while( totalBytesWritten < bufferSize );

   return bytesWritten;/*size_t*/
}

