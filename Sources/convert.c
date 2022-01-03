#include <stdlib.h>

int my_strlen (char const *str)
{
    int i;
    for(i = 0; str[i]; i++);
    return i;
}

int StrToInt(char* str){
    int puisMax = my_strlen(str) - 1, nb = 0;

    for(int i = 0; i < my_strlen(str); i++, puisMax--){
        int puis = 1;
        for(int x = puisMax; x; x--) puis *= 10;
        nb += (str[i] - '0') * puis;
    }

    return nb;
}

char* IntToStr(int number){

    char* buf = NULL;
    if(!number){
        buf = (char*)malloc(2 * sizeof(char));
        buf[0] = '0'; buf[1] = '\0';
    } else {
        int ifNeg = 0, nbDigit = 1;

        if (number < 0) {ifNeg = 1; number *= -1;}

        for(int i = number; (i = (i / 10)); nbDigit++);
        if(!(buf = (char*)malloc(sizeof(char)* (ifNeg + nbDigit + 1))))  return NULL; 
    
        if(ifNeg) buf[0] = '-';

        for(int i = nbDigit - 1 + ifNeg; number; i--){
                buf[i] = (number%10) + '0';
                number /= 10;
        }

        buf[nbDigit + ifNeg] = '\0';
    
    }
    return buf; //Attention faudra faire un free après manipulation
}
