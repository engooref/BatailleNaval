#ifndef PLAYER_H_
#define PLAYER_H_

#include "macro.h"

extern int varGlobal;

typedef struct	s_joueur
{
  char		map[MAP_SIZE*MAP_SIZE];
  //pid_t		pid;
  int		hit;
}t_joueur;

t_joueur* PlayerNew(const char* nameFilePos);
void PlayerDel(t_joueur* player);

int Player1(char* buf, char* mapEnemy, int pid);
int Player2(char* map, int pid);

#endif //PLAYER_H_