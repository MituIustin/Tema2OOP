#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Board.h"
#include "Piece.h"
#include "Player.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

class Game {
private:
    std::vector<std::shared_ptr<Piece>> pieces;
    std::vector <sf::Sprite> white_squares;
    Board board;
    Player first_player;
    Player second_player;

    void create_white_squares();
    void move_pieces(std::vector<sf::Texture>&, std::vector<sf::Sprite>& );

    void is_emp(int,int);

    static void finish(int, int ,int ,int );

public:
    Game();
    std::vector<std::shared_ptr<Piece>> & get_pieces();
    Game(const Game &other);
    void start_game();
};


#endif //OOP_GAME_H
