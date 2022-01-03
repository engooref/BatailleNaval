#include "IOConsole.h"
#include <stdlib.h>
#include <unistd.h>

void my_put_nbr (int nb)
{
    if(!nb) { my_putchar('0'); return; }
    
    char* buf = IntToStr(nb);
    if(!buf) return;

    my_putstr(buf);
    free(buf);
}

void my_putstr(char const *str)
{
    for(int i = 0 ; str[i]; i++) {
        my_putchar(str[i]);
    }
}

void my_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int ReadInput(char* buf, int len){
    int x = 0;
    
    while(!(x = read(STDIN_FILENO, buf, len)));
    x--;
    buf[x] = '\0';

    return x;
}
