#pragma once
#include "UnixSocket.h"
#include "ServerInterface.h"
#include <memory>
#include <netinet/in.h>
using namespace std;


class UnixSocketServer: public ServerInterface
{
   private:
      unique_ptr<Socket> mSock;

   protected:

   public:
      UnixSocketServer();
      virtual ~UnixSocketServer();
      virtual bool bind( unsigned int portNumber) override final;
      virtual bool listen( ) override final;
      virtual bool accept(  unique_ptr<Socket>&  ) override final;
};

