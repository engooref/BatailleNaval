#include "app.h"
#include "IOConsole.h"
#include <stdlib.h>

void my_h();

int main(int argc, char *argv[])
{
    if (((argc != 2) && (argc != 3)) || ((argv[1][0] == '-') && (argv[1][1] == 'h'))){
        my_h();
        return EXIT_SUCCESS;
    }

    AppNew(argc, argv);
    return EXIT_SUCCESS;
}

void my_h()
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");                                             //(fonction pour le -h)
    my_putstr("     first_player_pid: only for the ");
    my_putstr("2nd player. pid of the first player.\n");
    my_putstr("     navy_positions: file representing the positions of the ships.\n");
}