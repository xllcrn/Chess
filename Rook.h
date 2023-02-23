//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"
class Rook : public Piece{
public:
    Rook(ColorOfPieces color);
    ~Rook() noexcept override;
    bool isValid(Position const &,Position const &) override ;
private:
};


#endif //CHESS_ROOK_H
