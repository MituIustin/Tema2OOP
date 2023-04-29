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
    std::vector <sf::Sprite> white_squares;
    Board board;
    Player first_player;
    Player second_player;

    Rook white_rook_1{0} ;
    Rook white_rook_2{0} ;
    Rook black_rook_1{1} ;
    Rook black_rook_2{1} ;

    Knight white_knight_1{0};
    Knight white_knight_2{0};
    Knight black_knight_1{1};
    Knight black_knight_2{1};

    Bishop white_bishop_1{0};
    Bishop white_bishop_2{0};
    Bishop black_bishop_1{1};
    Bishop black_bishop_2{1};

    King white_king{0};
    King black_king{1};

    Queen white_queen{0};
    Queen black_queen{1};

    Pawn white_pawn_1{0};
    Pawn white_pawn_2{0};
    Pawn white_pawn_3{0};
    Pawn white_pawn_4{0};
    Pawn white_pawn_5{0};
    Pawn white_pawn_6{0};
    Pawn white_pawn_7{0};
    Pawn white_pawn_8{0};
    Pawn black_pawn_1{1};
    Pawn black_pawn_2{1};
    Pawn black_pawn_3{1};
    Pawn black_pawn_4{1};
    Pawn black_pawn_5{1};
    Pawn black_pawn_6{1};
    Pawn black_pawn_7{1};
    Pawn black_pawn_8{1};

    void create_white_squares();
    void move_pieces();

    void is_emp(int,int);

    static void finish(int, int ,int ,int );

public:
    std::vector<std::shared_ptr<Piece>> pieces;
    Game();
    Game(const Game &other);
    bool empty(int,int);
    void start_game();
};


#endif //OOP_GAME_H
