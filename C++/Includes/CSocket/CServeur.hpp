#ifndef CSERVEUR_H_
#define CSERVEUR_H_

#include "CSocket.hpp"

class CServeur : public CSocket
{
private:    
    SOCKET m_sockClient;
public:
    CServeur();
    ~CServeur();

    int AcceptClient();
};
#endif //CSERVEUR_H_