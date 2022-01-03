#ifndef CAPP_H_
#define CAPP_H_

#include <iostream>

#include "CSocket/CClient.hpp"
#include "CSocket/CServeur.hpp"

enum e_settings {
    SETTINGS_ONLINE = 0x01,
    SETTINGS_ONLINE_SERVER = 0x02,
    SETTING_ALL = 0xFF,
};

class CApp {
private:
    uint8_t m_settings;
    CServeur* m_pServeur;
    CClient* m_pClient;

public:
    CApp();
    ~CApp();
};
#endif //CAPP_H_
