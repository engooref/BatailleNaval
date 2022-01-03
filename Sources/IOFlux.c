#include "IOFlux.h"
#include "signalTraitement.h"
#include "IOConsole.h"

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

struct s_flux {
    int fd;
    int sigRecv;
}flux;

int FluxNew(char* name, int sigRecv){
    SignalNew(sigRecv, FLUXREAD);
    flux.sigRecv = sigRecv;
    if((flux.fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
        flux.fd = open(name, O_RDWR);
    return flux.fd;
}

void FluxDel(){
    SignalDel(flux.sigRecv);
    if(flux.fd != -1)  close(flux.fd);
}

int FluxWrite(char* buf, int pid){
    int i;
    for(i = 0; buf[i]; i++){
        write(flux.fd, buf + i, 1);
    }

    kill(pid, flux.sigRecv);
    return i;
}

int FluxRead(char* buf, int len){

    int x = read(flux.fd, buf, len);
    buf[x] = '\0';
    varGlobal = -10;
    return x;
}