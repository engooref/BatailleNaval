#include "app.h"

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    PLAYER_1 = 0x1,
    PLAYER_2 = 0x2,
    PLAYER_ALL = 0xF
}e_player;

static struct	s_app {
    t_joueur*	me;
    t_joueur*	enemy;
    e_player posPlayer;
    int pidOtherPlayer;
    int fd;
}app; //Unique


void AppNew(int argc, char* argv[]){
    /*******Configuration de la structure******/

    if(!( (app.me = PlayerNew((argc == 2) ? argv[1] : argv[2])) && (app.enemy = PlayerNew(NULL)) )) {
      my_putstr("Erreur d'initialisation des joueurs\n");
      exit(EXIT_FAILURE);
    }

    if(FluxNew("game", SIGUSR2) == -1) return;

    my_putstr("my pid: "); my_put_nbr((int)getpid()); my_putchar('\n');
    if(argc == 2){
        /****Player 1****/
        SignalNew(SIGUSR1, GETPID);
        my_putstr("waiting for enemy connection...\n");
        pause();
        my_putstr("\nenemy connected\n");
        app.pidOtherPlayer = varGlobal; SignalDel(SIGUSR1);
    } else {
        /****Player 2****/
        if(kill((app.pidOtherPlayer = StrToInt(argv[1])), SIGUSR1) == -1) { my_putstr("Erreur, mauvais PID\n"); return; }
        my_putstr("successfully connected\n");
    }
    
    
    app.posPlayer = (argc == 2) ? PLAYER_1 : PLAYER_2; 
    
    AppRun();
}

void AppDel() {
    /****Destruction de tous les élements (free, etc...) *****/
    if(app.me) PlayerDel(app.me);
    if(app.enemy) PlayerDel(app.enemy);
    FluxDel();
}

void AppRun() {
    /****Vie de l'application****/

    int quit = 0;
    char buf[256];    
    static e_player playPlayer = PLAYER_1;
   
    while(!quit){
        print_maps(app.me->map, app.enemy->map);
        if(app.posPlayer == playPlayer){
            do{
                my_putstr("attack: ");
                if((ReadInput(buf, 3) == 2) && (buf[1] != '\n')){
                    quit = Player1(buf, app.enemy->map, app.pidOtherPlayer);
                }
            } while(quit == -1);
        } else {
            quit = Player2(app.me->map, app.pidOtherPlayer);
        }
        
        playPlayer = (playPlayer == PLAYER_2) ? PLAYER_1 : PLAYER_2;
    };
    (playPlayer == app.posPlayer) ? my_putstr("\n\nI win\n\n") : my_putstr("\n\nI Loose\n\n");
    AppDel();
}
