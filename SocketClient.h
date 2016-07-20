#pragma once
#include "UnixSocket.h"
#include "ClientInterface.h"
#include <memory>
#include <string>
using namespace std;

class SocketClient: public ClientInterface
{
   private:
      unique_ptr<Socket> mSocketHandle;
      string mServerAddress;
      string mPortNumber;
   protected:

   public:
      SocketClient( );
      SocketClient( string, string );
      virtual ~SocketClient( );
      virtual bool connect( unique_ptr<Socket>& connectedSock ) override final;
      virtual void setServerAddress( char* ) override final;
      virtual void setPortNumber( char* ) override final;
};

