#include "Player.h"
#include "Exception.h"
#include <iostream>

Player::Player() {
    try {
        std::cout<<"Constructor Player\n";
        throw ClassNotUsed();
    }
    catch (const Exception& e) {
        std::cout<<"This class will be implemented in 'Tema 3 POO' ( "<<e.what()<<" ) .\n";
    }
}

Player::~Player() {
    std::cout<<"Destructor Player\n";
}