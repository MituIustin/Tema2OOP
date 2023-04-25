#include "Clase/Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    Game game;
    game.start_game();

    return 0;
}


/*
 * the structure of the project
 *
 * classes: board, piece, player, game +mostenire ( pawn, knight, horse, bishop, king, queen)
 *
 * in clasa "piece" functie virtuala : move (pt fiecare piesa in parte)
 * in clasa game atribut static : turn
 */