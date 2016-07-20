#pragma once
#include "InputOutputInterface.h"
#include "UnixSocket.h"
#include <memory>
using namespace std;

class ServerInterface
{
   public:
      virtual bool bind( unsigned int portNumber ) = 0;
      virtual bool listen( void ) = 0;
      virtual bool accept( unique_ptr<Socket>& ) = 0;
};

