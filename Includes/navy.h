/*
** PROJECT, 2021
** delivery
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_
#define GAME g_game

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct	s_position
{
  int		x;
  int		y;
}		t_position;



void print_result(int hit);
static void print_tableau(char t[8][9]);
void print_maps();

int hit(int h, char *i);
int map_hit(int h, char *i);
int entrer (char *i);
void win();


#endif /* !NAVY_H_ */

