#include "Pawn.h"
#include <iostream>
#include <cmath>
#include <memory>

#include "Game.h"

Pawn::Pawn(){
    std::cout<<"Constructor Pawn\n";
    alive = true;
    name = "pawn";
}

std::shared_ptr<Piece> Pawn::clone() const {
    std::cout<<"Constructor Clone Pawn\n";
    return std::make_shared<Pawn>( Pawn(*this) );
}

bool Pawn::move(int x1, int y1, int x2, int y2, bool ok) {
    if (x1==x2 && y1==y2) return false;
    if(color=="black")
    {
        if(y1==y2)
        {
            if(x1==1 && (x2-x1==1 || x2-x1==2) && ok == false) return true;
            if(x2-x1==1 && ok == false) return true;
        }
        else
        {
            if(abs(y1-y2)>1) return false;
            if(x2-x1==1 && abs(y2-y1)==1 && ok == true) return true;
        }
    }
    else
    {
        if(y1==y2)
        {
            if(x1==6 && (x1-x2==1 || x1-x2==2) && ok == false) return true;
            if(x1-x2==1 && ok == false) return true;
        }
        else
        {
            if(abs(y2-y1)>1) return false;
            if(x1-x2==1 && abs(y1-y2)==1 && ok == true) return true;
        }
    }
    return false;
}

Pawn::~Pawn() {
    std::cout<<"Destructor Pawn\n";
}