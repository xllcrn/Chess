//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"
class King :public Piece {
public:
    King(ColorOfPieces color);
    ~King() noexcept override;
    trajectory drawTraject(Position const &, bool, bool);
    bool isKing() const override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CHESS_KING_H
