#include "signalTraitement.h"

void SignalNew(int sig, sigAction actionHandler){
    struct sigaction sa;
    switch(actionHandler){
        case GETPID:
            sa.sa_flags = SA_SIGINFO;
            sa.sa_sigaction = GetPidHandler;
            break;
        case FLUXREAD:
            sa.sa_handler = FluxHandler;
            break;
    }

    sigaction(sig, &sa, NULL);
}

void SignalDel(int sig){
    signal(sig, SIG_DFL);
}