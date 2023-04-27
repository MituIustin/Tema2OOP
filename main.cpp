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

