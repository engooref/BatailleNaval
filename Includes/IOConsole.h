#ifndef PRINTCONSOLE_H_
#define PRINTCONSOLE_H_


#include "convert.h"

void my_put_nbr (int nb);
void my_putstr(char const *str);
void my_putchar(char c);

int ReadInput(char* buf, int len);
void Flush();
#endif //PRINTCONSOLE_H_