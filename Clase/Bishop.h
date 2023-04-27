#ifndef OOP_BISHOP_H
#define OOP_BISHOP_H

#include "Piece.h"
#include <string>

class Bishop : public Piece{
private:
    std::string name;
public:
    Bishop();
    explicit Bishop(int);
    Bishop(const Bishop&);
    Bishop & operator=(const Bishop&);
    bool move(int,int,int,int) override;
    ~Bishop();
};


#endif //OOP_BISHOP_H
