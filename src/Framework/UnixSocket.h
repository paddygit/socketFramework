#pragma once
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
   private:
   protected:
      int mSockHandle;
   public:
      Socket( int handle = -1): mSockHandle(handle){}
      virtual ~Socket( );
      operator int()
      {
         return mSockHandle;
      }
      Socket& operator= (int handle )
      {
         if( mSockHandle != handle )
         {
            mSockHandle = handle;
         }
         return *this;
      }

      virtual void setPortNumber( unsigned int ) = 0;
};

class StreamSocket: public Socket
{
   private:
      
   protected:

   public:
      StreamSocket( );
      StreamSocket( int );
      StreamSocket( int family, int type, int protocol);
      virtual void setPortNumber( unsigned int ) override;
      virtual ~StreamSocket( );
};
