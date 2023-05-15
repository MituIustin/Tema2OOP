#ifndef OOP_KING_H
#define OOP_KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class King : public Piece{
private:
    std::string name;
public:
    King();
    std::shared_ptr<Piece> clone() const override;
    King(const King&);
    King & operator=(const King&);
    bool move(int,int,int,int) override;
    ~King();
};

#endif //OOP_KING_H
