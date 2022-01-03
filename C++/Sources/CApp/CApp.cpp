#include "CApp/CApp.hpp"
#include "utils.h"

using namespace std;


CApp::CApp() :
    m_settings(0),
    m_pSocket(nullptr)
{
    cout << "Bienvenue dans la bataille naval !!!" << endl
    << "Pour commencer veuillez choisir un mode de jeux: " << endl
    << "\t1 - Un joueur (En développement)" << endl << "\t2 - Deux joueur (En ligne)" << endl
    << "Choix (1 ou 2): ";

    auto lambdaGetAndLimit = [](int min, int max) -> uint8_t {
        int bufUint = 0;
        do{
            cin >> bufUint;
            if((bufUint < min) || (bufUint > max)){
                cout << "Le choix ne peut être que entre " << min << " et " << max << endl; 
                cout << "Votre choix: ";
            }
        }while((bufUint < min) || (bufUint > max));
        return bufUint;
    };

    if(lambdaGetAndLimit(1, 2) == 2) mBitsSet(m_settings, SETTINGS_ONLINE);


    if(mIsBitsClr(m_settings, SETTINGS_ONLINE)){
        /* Partie Seul */
        /* En Construction */
    } else {
        /* Partie à deux */
        cout << "Voulez-vous héberger ou rejoindre une partie ?" << endl
        << "\t1 - Héberger" << endl << "\t2 - Rejoindre une partie" << endl;
        cout << "Votre choix (1 ou 2): ";
        
        if(lambdaGetAndLimit(1, 2) == 1) mBitsSet(m_settings, SETTINGS_ONLINE_SERVER);

        if(mIsBitsSet(m_settings, SETTINGS_ONLINE_SERVER)){
            m_pSocket = new CSocket(PORT);
			cout <<"Le serveur à démarrer sur le port " << PORT << endl;
			cout << "En attente d'une connexion..." << endl;
			if(m_pSocket.AcceptClient() == -1){
				cerr << "Le client n'a pas reussi à se connecté" << endl
				return;
			}

        } else {

        }
    }
}

CApp::~CApp(){

}
