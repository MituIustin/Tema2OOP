#ifndef OOP_BOARD_H
#define OOP_BOARD_H


class Board {
private:
    static const int rows = 8;
    static const int cols = 8;
    int number_of_pieces;
    void draw_pieces();
public:
    Board();

};


#endif //OOP_BOARD_H
