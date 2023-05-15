#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include "Piece.h"
#include <string>
#include <memory>

class Pawn : public Piece {
private:
    std::string name;
public:
    Pawn();
    std::shared_ptr<Piece> clone() const override;
    Pawn(const Pawn&);
    Pawn & operator=(const Pawn&);
    bool move(int,int,int,int) override;
    ~Pawn();
};


#endif //OOP_PAWN_H
