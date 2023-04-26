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

    bool var = true;
    bool par = true;                    //DE ELIMINAT
    for(int i=0; i<800; i+=100)
    {
        if(var == true) par = true;
        else par = false;

        for(int j=0; j<800; j+=100)
        {
            if(par)
            {
                par = false;
                sf::Texture whitewood_texture;
                if(!whitewood_texture.loadFromFile("Texturi/wsquare.PNG", sf::IntRect(0,0,100,100)))
                {
                    std::cout<<"eroare";
                }
                sf::Sprite whitewood_sprite;
                whitewood_sprite.setTexture(whitewood_texture);
                whitewood_sprite.setPosition(j,i);
                white_squares.push_back(whitewood_sprite);
            }
            else
            {
                par = true;
                sf::Texture darkwood_texture;
                if(!darkwood_texture.loadFromFile("Texturi/bsquare.PNG",sf::IntRect(0,0,100,100) ))
                {
                    std::cout<<"eroare";
                }
                sf::Sprite darkwood_sprite;
                darkwood_sprite.setTexture(darkwood_texture);
                darkwood_sprite.setPosition(j,i);
            }
        }

        if(var == true) var = false;
        else var = true;
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

            window.display();
        }
    }
}