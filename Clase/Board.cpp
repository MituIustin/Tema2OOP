#include "Board.h"
#include "Exception.h"
#include <iostream>

Board::Board() {
    try {
        std::cout<<"Constructor Board\n";
        throw ClassNotUsed();
    }
    catch (const Exception& e) {
        std::cout<<"This class will be implemented in 'Tema 3 POO' ( "<<e.what()<<" ) .\n";
    }

}

Board::~Board() {
    std::cout<<"Destructor Board\n";
}
