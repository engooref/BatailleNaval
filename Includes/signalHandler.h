#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include <signal.h>

void GetPidHandler(int sig, siginfo_t * info, void* context);
void FluxHandler(int sig);

#endif //SIGNALHANDLER_H_