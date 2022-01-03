#include "CSocket/CServeur.hpp"
#include <iostream>

using namespace std;

CServeur::CServeur() :
    m_sockClient(-1)
{   
    m_sin.sin_addr.s_addr = htonl(INADDR_ANY);
    m_sin.sin_family = AF_INET;
    m_sin.sin_port = htons(PORT);
    
    if(bind(m_sock, (SOCKADDR*)&m_sin, m_lenSin) == SOCKET_ERROR) {
        cout << "Erreur dans la fonction bind" << endl;
        return;
    }

    if(listen(m_sock, 1) == SOCKET_ERROR){
        cout << "Erreur dans la fonction listen" << endl;
        return;
    }

}

int CServeur::AcceptClient(){
    SOCKADDR_IN addrClient = { 0 };
    socklen_t lenClient = sizeof(addrClient);
    m_sockClient = accept(m_sock, (sockaddr*)&addrClient, &lenClient);
    if(m_sockClient == INVALID_SOCKET)
        cerr << "Client non connecté arret" << endl;
        
    return m_sockClient;
}
