#include "printMap.h"

#include "macro.h"

static void print_tableau(char* t) {
    my_putstr(" |");
    for(int i = 0; i < MAP_SIZE; i++){
      my_putchar('A' + i); my_putchar(' '); }

    my_putstr("\n-+");
    for(int i = 1; i < MAP_SIZE*2; i++) my_putchar('-');
    my_putstr("\n");

    for(int w = 0; w < MAP_SIZE; w++){
      my_put_nbr(w + 1);
      my_putstr("|");
      for(int h = 0; h < MAP_SIZE; h++){
            my_putchar(*(t + h*MAP_SIZE + w));
            my_putchar(' ');       
      }
      my_putchar('\n');
    }
}

void print_maps(char* mapMe, char* mapEnnemy) {
     my_putstr("\nmy positions :\n");
    print_tableau(mapMe);
    my_putstr("\nenemy's positions :\n");
    print_tableau(mapEnnemy);
    my_putstr("\n");
}