//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"

class Knight : public Piece{
public:
    Knight(ColorOfPieces color);
    ~Knight() noexcept override;
    bool isValid(Position const &,Position const &) override ;
    trajectory drawTraject(Position const &, bool=false) override;
private:
};


#endif //CHESS_KNIGHT_H
