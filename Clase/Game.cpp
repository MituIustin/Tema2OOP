#include "Game.h"
#include "Board.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

Game::Game() {
    std::cout<<"Constructor Game\n";
}
Game::Game(const Game &other) : board(other.board)
{
    std::cout<<"Constructor Game de copiere\n";
}

void Game::create_white_squares() {
    for(int i=0; i<800; i+=100)
    {
        for(int j=0; j<800; j+=100)
        {
            if((i+j)%200==0) {
                sf::Texture whitewood_texture;
                if (!whitewood_texture.loadFromFile("Texturi/wsquare.png", sf::IntRect(0, 0, 100, 100))) {
                    std::cout << "eroare";
                }
                sf::Sprite whitewood_sprite;
                whitewood_sprite.setTexture(whitewood_texture);
                whitewood_sprite.setPosition(j, i);
                white_squares.push_back(whitewood_sprite);
            }
        }
    }
}

void Game::move_pieces() {
    black_king.set_row_col(0, 4);
    white_king.set_row_col(7, 4);

    white_queen.set_row_col(7, 3);
    black_queen.set_row_col(0,3);

    white_rook_1.set_row_col(7,0);
    white_rook_2.set_row_col(7,7);
    black_rook_1.set_row_col(0,0);
    black_rook_2.set_row_col(0,7);

    white_knight_1.set_row_col(7,1);
    white_knight_2.set_row_col(7,6);
    black_knight_1.set_row_col(0,1);
    black_knight_2.set_row_col(0,6);

    white_bishop_1.set_row_col(7,2);
    white_bishop_2.set_row_col(7,5);
    black_bishop_1.set_row_col(0,2);
    black_bishop_2.set_row_col(0,5);

    white_pawn_1.set_row_col(6,0);
    white_pawn_2.set_row_col(6,1);
    white_pawn_3.set_row_col(6,2);
    white_pawn_4.set_row_col(6,3);
    white_pawn_5.set_row_col(6,4);
    white_pawn_6.set_row_col(6,5);
    white_pawn_7.set_row_col(6,6);
    white_pawn_8.set_row_col(6,7);
    black_pawn_1.set_row_col(1,0);
    black_pawn_2.set_row_col(1,1);
    black_pawn_3.set_row_col(1,2);
    black_pawn_4.set_row_col(1,3);
    black_pawn_5.set_row_col(1,4);
    black_pawn_6.set_row_col(1,5);
    black_pawn_7.set_row_col(1,6);
    black_pawn_8.set_row_col(1,7);

}


void Game::start_game() {

    move_pieces();
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess ");
    window.setVerticalSyncEnabled(true);

    create_white_squares();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear(sf::Color::Black);

            for (auto square : white_squares) window.draw(square);



            if(white_king.alive) window.draw(white_king.get_sprite());
            if(black_king.alive) window.draw(black_king.get_sprite());

            if(white_queen.alive) window.draw(white_queen.get_sprite());
            if(black_queen.alive) window.draw(black_queen.get_sprite());

            if(white_rook_1.alive) window.draw(white_rook_1.get_sprite());
            if(white_rook_2.alive) window.draw(white_rook_2.get_sprite());
            if(black_rook_1.alive) window.draw(black_rook_1.get_sprite());
            if(black_rook_2.alive) window.draw(black_rook_2.get_sprite());

            if(white_knight_1.alive) window.draw(white_knight_1.get_sprite());
            if(white_knight_2.alive) window.draw(white_knight_2.get_sprite());
            if(black_knight_1.alive) window.draw(black_knight_1.get_sprite());
            if(black_knight_2.alive) window.draw(black_knight_2.get_sprite());

            if(white_bishop_1.alive) window.draw(white_bishop_1.get_sprite());
            if(white_bishop_2.alive) window.draw(white_bishop_2.get_sprite());
            if(black_bishop_1.alive) window.draw(black_bishop_1.get_sprite());
            if(black_bishop_2.alive) window.draw(black_bishop_2.get_sprite());

            if(white_pawn_1.alive) window.draw(white_pawn_1.get_sprite());
            if(white_pawn_2.alive) window.draw(white_pawn_2.get_sprite());
            if(white_pawn_3.alive) window.draw(white_pawn_3.get_sprite());
            if(white_pawn_4.alive) window.draw(white_pawn_4.get_sprite());
            if(white_pawn_5.alive) window.draw(white_pawn_5.get_sprite());
            if(white_pawn_6.alive) window.draw(white_pawn_6.get_sprite());
            if(white_pawn_7.alive) window.draw(white_pawn_7.get_sprite());
            if(white_pawn_8.alive) window.draw(white_pawn_8.get_sprite());
            if(black_pawn_1.alive) window.draw(black_pawn_1.get_sprite());
            if(black_pawn_2.alive) window.draw(black_pawn_2.get_sprite());
            if(black_pawn_3.alive) window.draw(black_pawn_3.get_sprite());
            if(black_pawn_4.alive) window.draw(black_pawn_4.get_sprite());
            if(black_pawn_5.alive) window.draw(black_pawn_5.get_sprite());
            if(black_pawn_6.alive) window.draw(black_pawn_6.get_sprite());
            if(black_pawn_7.alive) window.draw(black_pawn_7.get_sprite());
            if(black_pawn_8.alive) window.draw(black_pawn_8.get_sprite());

            window.display();
        }
    }
}