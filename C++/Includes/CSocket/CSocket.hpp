#ifndef CSOCKET_H_
#define CSOCKET_H_

#ifdef linux

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

#elif defined WIN32

#include <winsock2.h>

#define closesocket(s) close (s)

typedef int socklen_t;

#endif

#include <thread>
#include <stdio.h>
#include <stdlib.h>

#define PORT	4000

class CSocket {
protected:
    SOCKET m_sock;
    SOCKADDR_IN m_sin;
    socklen_t m_lenSin;

protected:
    CSocket();
	~CSocket();

};
#endif //CSOCKET_H_
