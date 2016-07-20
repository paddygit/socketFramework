#pragma once
#include "InputOutputInterface.h"
#include "UnixSocket.h"
#include <memory>
using namespace std;

class ClientInterface
{
   public:
      virtual void setServerAddress( char* ) = 0;
      virtual void setPortNumber( char* ) = 0;
      virtual bool connect( unique_ptr<Socket>& ) = 0;
};

