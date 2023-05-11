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

Game& Game::operator=(const Game& other) {

    pieces.clear();
    for (const auto& piece : other.pieces) {
        if (const auto ptr_rook = std::dynamic_pointer_cast<Rook>(piece)) {
            pieces.emplace_back(std::make_shared<Rook>(*ptr_rook));
        }
        if (const auto ptr_knight = std::dynamic_pointer_cast<Knight>(piece)) {
            pieces.emplace_back(std::make_shared<Knight>(*ptr_knight));
        }
        if (const auto ptr_bishop = std::dynamic_pointer_cast<Bishop>(piece)) {
            pieces.emplace_back(std::make_shared<Bishop>(*ptr_bishop));
        }
        if (const auto ptr_king = std::dynamic_pointer_cast<King>(piece)) {
            pieces.emplace_back(std::make_shared<King>(*ptr_king));
        }
        if (const auto ptr_queen = std::dynamic_pointer_cast<Queen>(piece)) {
            pieces.emplace_back(std::make_shared<Queen>(*ptr_queen));
        }
        if (const auto ptr_pawn = std::dynamic_pointer_cast<Pawn>(piece)) {
            pieces.emplace_back(std::make_shared<Pawn>(*ptr_pawn));
        }
    }
    white_squares = other.white_squares;
    board = other.board;
    first_player = other.first_player;
    second_player = other.second_player;
    return *this;
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

void Game::create_piece(std::vector<sf::Texture> & textures, std::vector<sf::Sprite> & sprites, std::string texture_name, int x_start, int y_start, int x_final, int y_final, int x, int y, int & cnt, int n_piece) {
    if(!textures[cnt].loadFromFile(texture_name, sf::IntRect(x_start, y_start, x_final, y_final))) throw NoTexture();
    sprites[cnt].setTexture(textures[cnt]);
    sprites[cnt].setScale(float(100.0 / x_final), float(100.0 / y_final));
    if(n_piece == 0) pieces.emplace_back(std::make_shared<Rook>());
    if(n_piece == 1) pieces.emplace_back(std::make_shared<Knight>());
    if(n_piece == 2) pieces.emplace_back(std::make_shared<Bishop>());
    if(n_piece == 3) pieces.emplace_back(std::make_shared<King>());
    if(n_piece == 4) pieces.emplace_back(std::make_shared<Queen>());
    if(n_piece == 5) pieces.emplace_back(std::make_shared<Pawn>());
    pieces[cnt]->set_row_col(x, y);
    pieces[cnt]->set_sprite(sprites[cnt]);
    cnt++;
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
    std::vector<int> poz_x;
    std::vector<int> poz_y;
    std::vector<std::string> tex;

    create_piece(textures,sprites,"Texturi/whiteking.png",0,0,188,309,7,4,cnt,3);
    create_piece(textures,sprites,"Texturi/blackking.png",0,0,196,306,0,4,cnt,3);
    create_piece(textures,sprites,"Texturi/whitequeen.png",0,0,184,286,7,3,cnt,4);
    create_piece(textures,sprites,"Texturi/blackqueen.png",0,0,182,276,0,3,cnt,4);

    poz_x.push_back(7); poz_x.push_back(7); poz_x.push_back(0); poz_x.push_back(0);
    poz_y.push_back(2); poz_y.push_back(5); poz_y.push_back(2); poz_y.push_back(5);

    tex.push_back("Texturi/whitebishop.png"); tex.push_back("Texturi/whitebishop.png");
    tex.push_back("Texturi/blackbishop.png"); tex.push_back("Texturi/blackbishop.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures,sprites,tex[i],0,0,170,275,poz_x[i],poz_y[i],cnt,2);
    }

    poz_y.clear();
    tex.clear();

    poz_y.push_back(1); poz_y.push_back(6); poz_y.push_back(1); poz_y.push_back(6);
    tex.push_back("Texturi/whiteknight.png"); tex.push_back("Texturi/whiteknight.png");
    tex.push_back("Texturi/blackknight.png"); tex.push_back("Texturi/blackknight.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures,sprites,tex[i],0,0,185,285,poz_x[i],poz_y[i],cnt,1);
    }

    poz_y.clear();
    tex.clear();

    poz_y.push_back(0); poz_y.push_back(7); poz_y.push_back(0); poz_y.push_back(7);
    tex.push_back("Texturi/whiterook.png"); tex.push_back("Texturi/whiterook.png");
    tex.push_back("Texturi/blackrook.png"); tex.push_back("Texturi/blackrook.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures,sprites,tex[i],0,0,172,260,poz_x[i],poz_y[i],cnt,0);
    }

    for (int i = 0; i < 8; i++) {
        create_piece(textures,sprites,"Texturi/whitepawn.png",0,0,171,242,6,i,cnt,5);
    }
    for (int i = 0; i < 8; i++) {
        create_piece(textures,sprites,"Texturi/blackpawn.png",0,0,172,232,1,i,cnt,5);
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

                                if(pieces.size()==0) throw NoPieces();
                                else {
                                    bool ok = false;
                                    for (long unsigned int i = 0; i < pieces.size(); i++) {
                                        if (pieces[i]->move(c4, c3, c2, c1) && pieces[i]->get_row() == c3 && pieces[i]->get_col() == c4)
                                        {
                                            is_emp(c2, c1);
                                            pieces[i]->set_row_col(c2, c1);
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

                for (long unsigned int i = 0; i < pieces.size(); i++) {
                    if (pieces[i]->get_alive()) window.draw(pieces[i]->get_sprite());
                }

                window.display();
            }
        }

}