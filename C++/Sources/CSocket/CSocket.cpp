#include "CSocket/CSocket.hpp"


CSocket::CSocket() :
    m_lenSin(sizeof(m_sin)),
{
#ifdef WIN32
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);
#endif
    m_sock = socket(AF_INET, SOCK_STREAM, 0);
}



CSocket::~CSocket(){
#ifdef WIN32
    WSACleanup();
#endif
}

