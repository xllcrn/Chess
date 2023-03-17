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
    trajectory drawTraject(Position const &, bool) override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CHESS_KNIGHT_H
