#ifndef APP_H_
#define APP_H_

#include "IOConsole.h"
#include "IOFlux.h"
#include "player.h"
#include "printMap.h"
#include "signalTraitement.h"

extern int varGlobal;


void AppNew(int argc, char* argv[]);
void AppDel();
void AppRun();

#endif //APP_H_