#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"
#include <string>
#include <memory>

class Rook : public Piece{
private:
    std::string name;
public:
    Rook();
    std::shared_ptr<Piece> clone() const override;
    Rook (const Rook&);
    Rook & operator=(const Rook &);
    bool move(int,int,int,int) override;
    ~Rook();
};


#endif //OOP_ROOK_H
