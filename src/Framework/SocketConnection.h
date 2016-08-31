#pragma once
#include "InputOutputInterface.h"
#include "UnixSocket.h"
#include <memory>
#include <fcntl.h>
using namespace std;

class SocketConnection: public ReadWriteInterface
{
   private:
      unique_ptr<Socket> mSocket;
   protected:

   public:
      SocketConnection( Socket* socket ): mSocket( socket ) { }
      SocketConnection( unique_ptr<Socket>&& sock ): mSocket( std::move(sock) ) {}
      SocketConnection( int sockFD ) 
      {
         *mSocket = sockFD;
      }
      SocketConnection(  SocketConnection&& ref );
      virtual ~SocketConnection( ){}
      virtual size_t read( const char* buffer, size_t bufferSize ) override final;
      virtual size_t write( const char* buffer, size_t bufferSize ) override final;
};

