//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"
class Bishop : public Piece{
public:
    Bishop(ColorOfPieces color);
    ~Bishop() noexcept override;
    bool isValid(Position const &,Position const &) override ;
    trajectory drawTraject(Position const &) override;
private:
};


#endif //CHESS_BISHOP_H
