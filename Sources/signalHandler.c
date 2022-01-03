#include "signalHandler.h"
#include <IOConsole.h>

int varGlobal;

void GetPidHandler(int sig, siginfo_t * info, void* context){
    varGlobal = info->si_pid;
}

void FluxHandler(int sig){
    varGlobal = -1;   
}