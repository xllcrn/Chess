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
    trajectory drawTraject(Position const &, bool, bool) override;
    bool isInitialPosition(Position const & pos) const override;
private:
    bool hasMoved(Position const &);
};


#endif //CHESS_BISHOP_H
