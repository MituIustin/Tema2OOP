#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include "Piece.h"
#include <string>
#include <memory>

class Knight : public Piece{
private:
    std::string name;
public:
    Knight();
    std::shared_ptr<Piece> clone() const override;
    Knight(const Knight&);
    Knight& operator=(const Knight&);
    bool move(int,int,int,int) override;
    ~Knight();
};


#endif //OOP_KNIGHT_H
