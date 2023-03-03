//
// Created by xllcr on 22/02/2023.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(ColorOfPieces color);
    ~Pawn() noexcept override;
    bool isValid(Position const &,Position const &) override ;
    trajectory drawTraject(Position const &) override;
private:
};

#endif //CHESS_PAWN_H