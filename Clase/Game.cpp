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

    pieces.emplace_back(std::make_unique<King>(white_king));
    pieces[pieces.size()-1]->set_row_col(7,4);
    pieces[pieces.size()-1]->set_sprite(white_king.get_sprite());

    pieces.emplace_back(std::make_unique<King>(black_king));
    pieces[pieces.size()-1]->set_row_col(0,4);
    pieces[pieces.size()-1]->set_sprite(black_king.get_sprite());

    white_queen.set_row_col(7, 3);
    black_queen.set_row_col(0,3);

    pieces.emplace_back(std::make_unique<Queen>(white_queen));
    pieces[pieces.size()-1]->set_row_col(7,3);
    pieces[pieces.size()-1]->set_sprite(white_queen.get_sprite());

    pieces.emplace_back(std::make_unique<Queen>(black_queen));
    pieces[pieces.size()-1]->set_row_col(0,3);
    pieces[pieces.size()-1]->set_sprite(black_queen.get_sprite());

    white_rook_1.set_row_col(7,0);
    pieces.emplace_back(std::make_unique<Rook>(white_rook_1));
    pieces[pieces.size()-1]->set_row_col(7,0);
    pieces[pieces.size()-1]->set_sprite(white_rook_1.get_sprite());

    white_rook_2.set_row_col(7,7);
    pieces.emplace_back(std::make_unique<Rook>(white_rook_2));
    pieces[pieces.size()-1]->set_row_col(7,7);
    pieces[pieces.size()-1]->set_sprite(white_rook_2.get_sprite());


    black_rook_1.set_row_col(0,0);
    pieces.emplace_back(std::make_unique<Rook>(black_rook_1));
    pieces[pieces.size()-1]->set_row_col(0,0);
    pieces[pieces.size()-1]->set_sprite(black_rook_1.get_sprite());


    black_rook_2.set_row_col(0,7);
    pieces.emplace_back(std::make_unique<Rook>(black_rook_2));
    pieces[pieces.size()-1]->set_row_col(0,7);
    pieces[pieces.size()-1]->set_sprite(black_rook_2.get_sprite());

    white_knight_1.set_row_col(7,1);
    pieces.emplace_back(std::make_unique<Knight>(white_knight_1));
    pieces[pieces.size()-1]->set_row_col(7,1);
    pieces[pieces.size()-1]->set_sprite(white_knight_1.get_sprite());

    white_knight_2.set_row_col(7,6);
    pieces.emplace_back(std::make_unique<Knight>(white_knight_2));
    pieces[pieces.size()-1]->set_row_col(7,6);
    pieces[pieces.size()-1]->set_sprite(white_knight_2.get_sprite());


    black_knight_1.set_row_col(0,1);
    pieces.emplace_back(std::make_unique<Knight>(black_knight_1));
    pieces[pieces.size()-1]->set_row_col(0,1);
    pieces[pieces.size()-1]->set_sprite(black_knight_1.get_sprite());


    black_knight_2.set_row_col(0,6);
    pieces.emplace_back(std::make_unique<Knight>(black_knight_2));
    pieces[pieces.size()-1]->set_row_col(0,6);
    pieces[pieces.size()-1]->set_sprite(black_knight_2.get_sprite());


    white_bishop_1.set_row_col(7,2);
    pieces.emplace_back(std::make_unique<Bishop>(white_bishop_1));
    pieces[pieces.size()-1]->set_row_col(7,2);
    pieces[pieces.size()-1]->set_sprite(white_bishop_1.get_sprite());


    white_bishop_2.set_row_col(7,5);
    pieces.emplace_back(std::make_unique<Bishop>(white_bishop_2));
    pieces[pieces.size()-1]->set_row_col(7,5);
    pieces[pieces.size()-1]->set_sprite(white_bishop_2.get_sprite());


    black_bishop_1.set_row_col(0,2);
    pieces.emplace_back(std::make_unique<Bishop>(black_bishop_1));
    pieces[pieces.size()-1]->set_row_col(0,2);
    pieces[pieces.size()-1]->set_sprite(black_bishop_1.get_sprite());


    black_bishop_2.set_row_col(0,5);
    pieces.emplace_back(std::make_unique<Bishop>(black_bishop_2));
    pieces[pieces.size()-1]->set_row_col(0,5);
    pieces[pieces.size()-1]->set_sprite(black_bishop_2.get_sprite());


    white_pawn_1.set_row_col(6,0);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_1));
    pieces[pieces.size()-1]->set_row_col(6,0);
    pieces[pieces.size()-1]->set_sprite(white_pawn_1.get_sprite());


    white_pawn_2.set_row_col(6,1);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_2));
    pieces[pieces.size()-1]->set_row_col(6,1);
    pieces[pieces.size()-1]->set_sprite(white_pawn_2.get_sprite());


    white_pawn_3.set_row_col(6,2);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_3));
    pieces[pieces.size()-1]->set_row_col(6,2);
    pieces[pieces.size()-1]->set_sprite(white_pawn_3.get_sprite());


    white_pawn_4.set_row_col(6,3);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_4));
    pieces[pieces.size()-1]->set_row_col(6,3);
    pieces[pieces.size()-1]->set_sprite(white_pawn_4.get_sprite());


    white_pawn_5.set_row_col(6,4);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_5));
    pieces[pieces.size()-1]->set_row_col(6,4);
    pieces[pieces.size()-1]->set_sprite(white_pawn_5.get_sprite());


    white_pawn_6.set_row_col(6,5);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_6));
    pieces[pieces.size()-1]->set_row_col(6,5);
    pieces[pieces.size()-1]->set_sprite(white_pawn_6.get_sprite());


    white_pawn_7.set_row_col(6,6);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_7));
    pieces[pieces.size()-1]->set_row_col(6,6);
    pieces[pieces.size()-1]->set_sprite(white_pawn_7.get_sprite());


    white_pawn_8.set_row_col(6,7);
    pieces.emplace_back(std::make_unique<Pawn>(white_pawn_8));
    pieces[pieces.size()-1]->set_row_col(6,7);
    pieces[pieces.size()-1]->set_sprite(white_pawn_8.get_sprite());


    black_pawn_1.set_row_col(1,0);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_1));
    pieces[pieces.size()-1]->set_row_col(1,0);
    pieces[pieces.size()-1]->set_sprite(black_pawn_1.get_sprite());


    black_pawn_2.set_row_col(1,1);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_2));
    pieces[pieces.size()-1]->set_row_col(1,1);
    pieces[pieces.size()-1]->set_sprite(black_pawn_2.get_sprite());


    black_pawn_3.set_row_col(1,2);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_3));
    pieces[pieces.size()-1]->set_row_col(1,2);
    pieces[pieces.size()-1]->set_sprite(black_pawn_3.get_sprite());


    black_pawn_4.set_row_col(1,3);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_4));
    pieces[pieces.size()-1]->set_row_col(1,3);
    pieces[pieces.size()-1]->set_sprite(black_pawn_4.get_sprite());


    black_pawn_5.set_row_col(1,4);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_5));
    pieces[pieces.size()-1]->set_row_col(1,4);
    pieces[pieces.size()-1]->set_sprite(black_pawn_5.get_sprite());


    black_pawn_6.set_row_col(1,5);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_6));
    pieces[pieces.size()-1]->set_row_col(1,5);
    pieces[pieces.size()-1]->set_sprite(black_pawn_6.get_sprite());


    black_pawn_7.set_row_col(1,6);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_7));
    pieces[pieces.size()-1]->set_row_col(1,6);
    pieces[pieces.size()-1]->set_sprite(black_pawn_7.get_sprite());


    black_pawn_8.set_row_col(1,7);
    pieces.emplace_back(std::make_unique<Pawn>(black_pawn_8));
    pieces[pieces.size()-1]->set_row_col(1,7);
    pieces[pieces.size()-1]->set_sprite(black_pawn_8.get_sprite());


}

void Game::is_emp(int y, int x) {

    for(long unsigned int i = 0; i<pieces.size(); i++)
    {
        if(pieces[i]->row == x and pieces[i]->col == y)
        {
            pieces[i]->set_row_col(9,9);
            pieces[i]->alive = false;

        }

    }
}

void Game::start_game() {

    move_pieces();

    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess ");
    window.setVerticalSyncEnabled(true);

    create_white_squares();

    int c1=0,c2=0,c3,c4;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if(c1 == 0 && c2 == 0)
                    {
                        c1 = event.mouseButton.x/100;
                        c2 = event.mouseButton.y/100;
                    }
                    else
                    {
                        c3 = c1;
                        c4 = c2;
                        c1 = event.mouseButton.x/100;
                        c2 = event.mouseButton.y/100;
                        std::cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<"\n";

                        for (long unsigned int i =0; i<pieces.size(); i++)
                        {
                            if(pieces[i]->move(c4,c3,c2,c1) && pieces[i]->row == c3 && pieces[i]->col == c4)
                            {
                                is_emp(c2,c1);
                                pieces[i]->set_row_col(c2,c1);
                            }
                        }
                        c1 = 0;
                        c2 = 0;
                    }
                }
            }


            window.clear(sf::Color::Black);

            for (auto square : white_squares) window.draw(square);

            for (long unsigned int i =0; i<pieces.size(); i++)
            {
                if(pieces[i]->alive) window.draw(pieces[i]->get_sprite());
            }

            window.display();
        }
    }
}