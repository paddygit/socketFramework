#pragma once
#include <cstddef>
using namespace std;

class ReadInterface
{
   public:
      virtual size_t read( const char* buffer, size_t bufferSize ) = 0;
};

class WriteInterface
{
   public:
      virtual size_t write( const char* buffer, size_t bufferSize ) = 0;
};

class ReadWriteInterface: public ReadInterface, public WriteInterface
{
};
