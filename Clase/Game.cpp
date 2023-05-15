#include "Game.h"
#include "Exception.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() {
    std::cout<<"Constructor Game\n";
    pieceConstructors = {
            {PieceType::ROOK, []() { return std::make_shared<Rook>(); }},
            {PieceType::KNIGHT, []() { return std::make_shared<Knight>(); }},
            {PieceType::BISHOP, []() { return std::make_shared<Bishop>(); }},
            {PieceType::KING, []() { return std::make_shared<King>(); }},
            {PieceType::QUEEN, []() { return std::make_shared<Queen>(); }},
            {PieceType::PAWN, []() { return std::make_shared<Pawn>(); }}
    };
}

Game::Game(const Game &other) :
pieceConstructors (other.pieceConstructors),
white_squares (other.white_squares),
board(other.board),
first_player(other.first_player),
second_player(other.second_player)
{
    pieces.clear();
    for( long long unsigned int i=0; i<other.pieces.size(); i++)
    {
        std::shared_ptr<Piece> piece_clone = other.pieces[i]->clone();
        pieces.emplace_back(piece_clone);
    }
}

Game& Game::operator=(const Game& other) {

    pieces.clear();

    for (const auto& piece : other.pieces) {
        pieces.emplace_back(piece->clone());
    }

    pieceConstructors = other.pieceConstructors;
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

void Game::create_piece(sf::Texture& texture, sf::Sprite& sprite, std::string texture_name, int x_final, int y_final, int x, int y, int n_piece) {
    if (!texture.loadFromFile(texture_name, sf::IntRect(0, 0, x_final, y_final)))
        throw NoTexture();

    sprite.setTexture(texture);
    sprite.setScale(100.0f / x_final, 100.0f / y_final);

    PieceType pieceType = static_cast<PieceType>(n_piece);
    auto it = pieceConstructors.find(pieceType);

    pieces.emplace_back((it->second)());
    pieces.back()->set_row_col(x, y);
    pieces.back()->set_sprite(sprite);
}


std::vector<std::shared_ptr<Piece>> & Game::get_pieces() {
    return pieces;
}

void Game::is_emp(int y, int x) {

    if ( y<0 || y>7 || x<0 || x>7) throw NotValidPosition();
    for(long unsigned int i = 0; i<pieces.size(); i++)
    {
        if(pieces[i]->get_row() == x && pieces[i]->get_col() == y)
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

    create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/whiteking.png",188,309,7,4,3);
    create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/blackking.png",196,306,0,4,3);
    create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/whitequeen.png",184,286,7,3,4);
    create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/blackqueen.png",182,276,0,3,4);

    poz_x.push_back(7); poz_x.push_back(7); poz_x.push_back(0); poz_x.push_back(0);
    poz_y.push_back(2); poz_y.push_back(5); poz_y.push_back(2); poz_y.push_back(5);

    tex.push_back("Texturi/whitebishop.png"); tex.push_back("Texturi/whitebishop.png");
    tex.push_back("Texturi/blackbishop.png"); tex.push_back("Texturi/blackbishop.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures[pieces.size()],sprites[pieces.size()],tex[i],170,275,poz_x[i],poz_y[i],2);
    }

    poz_y.clear();
    tex.clear();

    poz_y.push_back(1); poz_y.push_back(6); poz_y.push_back(1); poz_y.push_back(6);
    tex.push_back("Texturi/whiteknight.png"); tex.push_back("Texturi/whiteknight.png");
    tex.push_back("Texturi/blackknight.png"); tex.push_back("Texturi/blackknight.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures[pieces.size()],sprites[pieces.size()],tex[i],185,285,poz_x[i],poz_y[i],1);
    }

    poz_y.clear();
    tex.clear();

    poz_y.push_back(0); poz_y.push_back(7); poz_y.push_back(0); poz_y.push_back(7);
    tex.push_back("Texturi/whiterook.png"); tex.push_back("Texturi/whiterook.png");
    tex.push_back("Texturi/blackrook.png"); tex.push_back("Texturi/blackrook.png");

    for(int i=0; i<4; i++)
    {
        create_piece(textures[pieces.size()],sprites[pieces.size()],tex[i],172,260,poz_x[i],poz_y[i],0);
    }

    for (int i = 0; i < 8; i++) {
        create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/whitepawn.png",171,242,6,i,5);
    }
    for (int i = 0; i < 8; i++) {
        create_piece(textures[pieces.size()],sprites[pieces.size()],"Texturi/blackpawn.png",172,232,1,i,5);
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