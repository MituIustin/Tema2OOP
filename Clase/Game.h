#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Board.h"
#include "Piece.h"
#include "Player.h"

#include <vector>

class Game {
private:
    Board board;
    Player first_player;
    Player second_player;

public:
    Game();
    Game(const Game &other) ;
    void create_pieces();
    void start_game();
};


#endif //OOP_GAME_H
