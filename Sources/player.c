#include "player.h"
#include "IOFlux.h"
#include "IOConsole.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


t_joueur* PlayerNew(const char* nameFilePos){
    t_joueur* newPlayer = (t_joueur*)malloc(sizeof(t_joueur));
    if(!newPlayer) return NULL;
    for(int i = 0; i < MAP_SIZE*MAP_SIZE; i++) newPlayer->map[i] = '.';
    if(nameFilePos){
        FILE* filePos = NULL; char* line = NULL; size_t len = 0;
        if(!(filePos = fopen(nameFilePos, "r"))) {free(newPlayer); return NULL; }
        while(getline(&line, &len, filePos) != -1) {
            for(int x = 0, diffX = (line[5] - line[2]); (diffX + 1) ;((diffX < 0) ? (diffX++, x--) : (diffX--, x++))){
                *(newPlayer->map + ((line[2] - 'A') + x)*MAP_SIZE + (line[3] - '0' - 1)) = line[0];
            }
            for(int y = 0, diffY = (line[6] - line[3]); diffY; ((diffY < 0) ? (diffY++, y--) : (diffY--, y++))){
                *(newPlayer->map + (line[2] - 'A')*MAP_SIZE + ((line[3] - '0') + y)) = line[0];
            }

        }
        fclose(filePos);
    }
    return newPlayer;
}

void PlayerDel(t_joueur* player){
    free(player);
    player = NULL;
}


int Player1(char* coord, char* mapEnemy, int pid){
    char buf[1];

    if(((coord[0] - '@' < 0) || (coord[0] - '@' > MAP_SIZE)) || 
       ((coord[1] - '0' < 0) || (coord[1] - '0' > MAP_SIZE)) ||
       (*(mapEnemy + (coord[0] - 'A') * MAP_SIZE + (coord[1] - '1')) != '.')){ my_putstr("Wrong position\n"); return -1; }

    FluxWrite(coord, pid);

    do {usleep(10);} while(varGlobal != -1);
    FluxRead(buf, 1);
    
    *(mapEnemy + (coord[0] - 'A') * MAP_SIZE + (coord[1] - '1')) = buf[0];
    
    my_putstr(coord); my_putstr(": ");
    (buf[0] == 'x') ? my_putstr("hit\n") : my_putstr("missed\n");
    do {usleep(10);} while(varGlobal != -1);
    FluxRead(buf, 1);
    return (buf[0] - '0');
}

int Player2(char* map, int pid){
#define BUF_SIZE 256
    char buf[BUF_SIZE];
    my_putstr("\nWaiting for ennemy's attack...");
    do {usleep(10);} while(varGlobal != -1);
    FluxRead(buf, BUF_SIZE);
    char* c = map + (buf[0] - 'A') * MAP_SIZE + (buf[1] - '1');
    if(*c != '.'){*c = 'x'; FluxWrite("x", pid);}
    else         {*c = 'o'; FluxWrite("o", pid);}

    int ret = 1;
    for(int i = 0; i < MAP_SIZE*MAP_SIZE; i++){
        for(int x = 0; x < 5; x++){
            if(!(map[i] - (x + '1'))){
                ret = 0;
                break;
            }
        }
        if(!ret) break;
    }
    usleep(500);
    char* bufWrite = IntToStr(ret);
    FluxWrite(bufWrite, pid);
    free(bufWrite);
    return ret;
}