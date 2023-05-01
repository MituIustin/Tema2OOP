#include "Game.h"
#include "Exception.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() {
    std::cout<<"Constructor Game\n";
}

Game::Game(const Game &other) :
white_squares (other.white_squares),
board(other.board),
first_player(other.first_player),
second_player(other.second_player)
{
    pieces.clear();
    for( long long unsigned int i=0; i<other.pieces.size(); i++)
    {
        Piece * piece_clone = other.pieces[i]->clone();
        pieces.emplace_back(piece_clone);
    }
}

void Game::create_white_squares() {
        for(int i=0; i<800; i+=100)
        {
            for(int j=0; j<800; j+=100)
            {
                if((i+j)%200==0) {
                    sf::Texture whitewood_texture;

                        if (!whitewood_texture.loadFromFile("Texturi/wsquare.png", sf::IntRect(0, 0, 100, 100)))
                            throw NoTexture();

                    sf::Sprite whitewood_sprite;
                    whitewood_sprite.setTexture(whitewood_texture);
                    whitewood_sprite.setPosition(j, i);
                    white_squares.push_back(whitewood_sprite);
                }
            }
        }
}

std::vector<std::shared_ptr<Piece>> & Game::get_pieces() {
    return pieces;
}

void Game::is_emp(int y, int x) {

    for(long unsigned int i = 0; i<get_pieces().size(); i++)
    {
        if(get_pieces()[i]->get_row() == x && get_pieces()[i]->get_col() == y)
        {
            get_pieces()[i]->set_row_col(9,9);
            get_pieces()[i]->set_alive(false);

        }

    }
}

void Game::finish(int c1, int c2, int c3, int c4) {
    std::cout<<"Piesa mutata de la ( "<<c4<<" , "<<c3<<" ) la ( "<<c2<<" , "<<c1<<" ). \n";
}


void Game::move_pieces(std::vector<sf::Texture>& textures, std::vector<sf::Sprite>& sprites) {
    int cnt = 0;
        if(!textures[cnt].loadFromFile("Texturi/whiteking.png", sf::IntRect(0, 0, 188, 309))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 188), float(100.0 / 309));
        pieces.emplace_back(std::make_shared<King>());
        pieces[cnt]->set_row_col(7, 4);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackking.png", sf::IntRect(0, 0, 196, 306))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 196), float(100.0 / 306));
        pieces.emplace_back(std::make_shared<King>());
        pieces[cnt]->set_row_col(0, 4);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whitequeen.png", sf::IntRect(0, 0, 184, 286))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 184), float(100.0 / 286));
        pieces.emplace_back(std::make_shared<Queen>());
        pieces[cnt]->set_row_col(7, 3);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackqueen.png", sf::IntRect(0, 0, 182, 276))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 182), float(100.0 / 276));
        pieces.emplace_back(std::make_shared<Queen>());
        pieces[cnt]->set_row_col(0, 3);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whitebishop.png", sf::IntRect(0, 0, 163, 275))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 163), float(100.0 / 275));
        pieces.emplace_back(std::make_shared<Bishop>());
        pieces[cnt]->set_row_col(7, 2);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whitebishop.png", sf::IntRect(0, 0, 163, 275))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 163), float(100.0 / 275));
        pieces.emplace_back(std::make_shared<Bishop>());
        pieces[cnt]->set_row_col(7, 5);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackbishop.png", sf::IntRect(0, 0, 178, 272))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 178), float(100.0 / 272));
        pieces.emplace_back(std::make_shared<Bishop>());
        pieces[cnt]->set_row_col(0, 2);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackbishop.png", sf::IntRect(0, 0, 178, 272))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 178), float(100.0 / 272));
        pieces.emplace_back(std::make_shared<Bishop>());
        pieces[cnt]->set_row_col(0, 5);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whiteknight.png", sf::IntRect(0, 0, 183, 295))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 183), float(100.0 / 295));
        pieces.emplace_back(std::make_shared<Knight>());
        pieces[cnt]->set_row_col(7, 1);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whiteknight.png", sf::IntRect(0, 0, 183, 295))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 183), float(100.0 / 295));
        pieces.emplace_back(std::make_shared<Knight>());
        pieces[cnt]->set_row_col(7, 6);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackknight.png", sf::IntRect(0, 0, 195, 279))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 195), float(100.0 / 279));
        pieces.emplace_back(std::make_shared<Knight>());
        pieces[cnt]->set_row_col(0, 1);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackknight.png", sf::IntRect(0, 0, 195, 279))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 195), float(100.0 / 279));
        pieces.emplace_back(std::make_shared<Knight>());
        pieces[cnt]->set_row_col(0, 6);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whiterook.png", sf::IntRect(0, 0, 182, 260))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 182), float(100.0 / 260));
        pieces.emplace_back(std::make_shared<Rook>());
        pieces[cnt]->set_row_col(7, 0);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/whiterook.png", sf::IntRect(0, 0, 182, 260))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 182), float(100.0 / 260));
        pieces.emplace_back(std::make_shared<Rook>());
        pieces[cnt]->set_row_col(7, 7);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackrook.png", sf::IntRect(0, 0, 162, 263))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 182), float(100.0 / 263));
        pieces.emplace_back(std::make_shared<Rook>());
        pieces[cnt]->set_row_col(0, 0);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;
        if(!textures[cnt].loadFromFile("Texturi/blackrook.png", sf::IntRect(0, 0, 162, 263))) throw NoTexture();
        sprites[cnt].setTexture(textures[cnt]);
        sprites[cnt].setScale(float(100.0 / 182), float(100.0 / 263));
        pieces.emplace_back(std::make_shared<Rook>());
        pieces[cnt]->set_row_col(0, 7);
        pieces[cnt]->set_sprite(sprites[cnt]);
        cnt++;

        for (int i = 0; i < 8; i++) {
            if(!textures[cnt].loadFromFile("Texturi/whitepawn.png", sf::IntRect(0, 0, 171, 242))) throw NoTexture();
            sprites[cnt].setTexture(textures[cnt]);
            sprites[cnt].setScale(float(100.0 / 171), float(100.0 / 242));
            pieces.emplace_back(std::make_shared<Pawn>());
            pieces[cnt]->set_row_col(6, i);
            pieces[cnt]->set_sprite(sprites[cnt]);
            cnt++;
        }

        for (int i = 0; i < 8; i++) {
            if(!textures[cnt].loadFromFile("Texturi/blackpawn.png", sf::IntRect(0, 0, 172, 232))) throw NoTexture();
            sprites[cnt].setTexture(textures[cnt]);
            sprites[cnt].setScale(float(100.0 / 172), float(100.0 / 232));
            pieces.emplace_back(std::make_shared<Pawn>());
            pieces[cnt]->set_row_col(1, i);
            pieces[cnt]->set_sprite(sprites[cnt]);
            cnt++;
        }
}

void Game::start_game() {



        std::vector<sf::Texture> textures;
        std::vector<sf::Sprite> sprites;
    try {

        for (int i = 1; i <= 32; i++) {
            sf::Texture texture;
            sf::Sprite sprite;
            textures.push_back(texture);
            sprites.push_back(sprite);
        }

        move_pieces(textures, sprites);
    }
    catch (const Exception &e) {
        std::cout << "Error: " << e.what();
    }


        sf::RenderWindow window(sf::VideoMode(800, 800), "Chess ");
        window.setVerticalSyncEnabled(true);

        create_white_squares();

        if (!window.isOpen()) throw WindowNotOpened();

        int c1 = 0, c2 = 0, c3, c4;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (c1 == 0 && c2 == 0) {
                            c1 = event.mouseButton.x / 100;
                            c2 = event.mouseButton.y / 100;
                        } else {
                            c3 = c1;
                            c4 = c2;
                            c1 = event.mouseButton.x / 100;
                            c2 = event.mouseButton.y / 100;

                            try {

                                if(get_pieces().size()==0) throw NoPieces();
                                else {
                                    bool ok = false;
                                    for (long unsigned int i = 0; i < get_pieces().size(); i++) {
                                        if (get_pieces()[i]->move(c4, c3, c2, c1) && get_pieces()[i]->get_row() == c3 && get_pieces()[i]->get_col() == c4 && ! (c1==c3 && c2==c4))
                                        {
                                            is_emp(c2, c1);
                                            get_pieces()[i]->set_row_col(c2, c1);
                                            finish(c1, c2, c3, c4);
                                            ok = true;
                                        }
                                    }
                                    if(ok == false) throw NotValidMove();

                                }
                            }
                            catch (const Exception &e) {
                                std::cout << "Error: " << e.what();
                            }
                            c1 = 0;
                            c2 = 0;

                        }
                    }
                }

                window.clear(sf::Color::Black);

                for (auto square: white_squares) window.draw(square);

                for (long unsigned int i = 0; i < get_pieces().size(); i++) {
                    if (get_pieces()[i]->get_alive()) window.draw(get_pieces()[i]->get_sprite());
                }

                window.display();
            }
        }

}