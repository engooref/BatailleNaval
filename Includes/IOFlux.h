#ifndef IOFLUX_H_
#define IOFLUX_H_

extern int varGlobal;

int FluxNew(char* name, int sigRecv);
void FluxDel();

int FluxWrite(char* buf, int pid);
int FluxRead(char* buf, int len);
#endif //IOFLUX_H_