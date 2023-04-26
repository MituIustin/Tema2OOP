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

void Game::start_game() {

    first_player.create_pieces();
    second_player.create_pieces();

    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess ");
    window.setVerticalSyncEnabled(true);

    std::vector <sf::Sprite> white_squares;
    std::vector <sf::Sprite> black_squares;

    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("Texturi/blackking.png",sf::IntRect(0,0,100,100));
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(200,100);


    for(int i=0; i<800; i+=100)
    {
        for(int j=0; j<800; j+=100)
        {
           if(i/100%2==0) {
               if(j/100%2==0) {
                   sf::Texture whitewood_texture;
                   if (!whitewood_texture.loadFromFile("Texturi/wsquare.PNG", sf::IntRect(0, 0, 100, 100))) {
                       std::cout << "eroare";
                   }
                   sf::Sprite whitewood_sprite;
                   whitewood_sprite.setTexture(whitewood_texture);
                   whitewood_sprite.setPosition(j, i);
                   white_squares.push_back(whitewood_sprite);
               }
                else {
                   sf::Texture darkwood_texture;
                   if (!darkwood_texture.loadFromFile("Texturi/bsquare.png", sf::IntRect(0, 0, 100, 100))) {
                       std::cout << "eroare";
                   }
                   sf::Sprite darkwood_sprite;
                   darkwood_sprite.setTexture(darkwood_texture);
                   darkwood_sprite.setPosition(j, i);
               }
           }
           else
           {
               if(j/100%2==1) {
                   sf::Texture whitewood_texture;
                   if (!whitewood_texture.loadFromFile("Texturi/wsquare.PNG", sf::IntRect(0, 0, 100, 100))) {
                       std::cout << "eroare";
                   }
                   sf::Sprite whitewood_sprite;
                   whitewood_sprite.setTexture(whitewood_texture);
                   whitewood_sprite.setPosition(j, i);
                   white_squares.push_back(whitewood_sprite);
               }
               else {
                   sf::Texture darkwood_texture;
                   if (!darkwood_texture.loadFromFile("Texturi/bsquare.png", sf::IntRect(0, 0, 100, 100))) {
                       std::cout << "eroare";
                   }
                   sf::Sprite darkwood_sprite;
                   darkwood_sprite.setTexture(darkwood_texture);
                   darkwood_sprite.setPosition(j, i);
               }
           }
        }


    }



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
            for (auto square : black_squares) window.draw(square);
            //board.draw_pieces();
            window.draw(sprite);

            window.display();
        }
    }
}