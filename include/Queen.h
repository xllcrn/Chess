//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"

class Queen : public Piece{
public:
    Queen(ColorOfPieces color);
    ~Queen() noexcept override;
    bool isValid(Position const &,Position const &) override ;
    trajectory drawTraject(Position const &) override;
private:
};


#endif //CHESS_QUEEN_H
