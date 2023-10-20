#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <string>

class Piece {
    private: int row, col;
    static int number_of_pieces;

    public: Piece();
    virtual std::shared_ptr < Piece > clone() const = 0;
    virtual~Piece();
    virtual bool move(int, int, int, int, bool) = 0;
    void set_row_col(int, int);
    int get_row();
    int get_col();
    std::string get_color();
    void set_color(std::string);
    bool get_alive();
    void set_alive(bool);
    void set_sprite(sf::Sprite);
    sf::Sprite get_sprite();
    Piece(const Piece & );
    Piece & operator = (const Piece & );
    std::string get_name();

    protected: bool alive;
    std::string color;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //OOP_PIECE_H

//CLASA ABSTRACTA
