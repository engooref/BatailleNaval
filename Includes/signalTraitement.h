#ifndef SIGNALTRAITEMENT_H_
#define SIGNALTRAITEMENT_H_

#include "signalHandler.h"

typedef enum e_sigaction {
    GETPID = 0,
    FLUXREAD,
}sigAction;

void SignalNew(int sig, sigAction actionHandler);
void SignalDel(int sig);


#endif //SIGNALTRAITEMENT_H_