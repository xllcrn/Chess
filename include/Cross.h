//
// Created by xllcr on 14/03/2023.
//

#ifndef CPP_CHESSGAME_CROSS_H
#define CPP_CHESSGAME_CROSS_H
#include "Piece.h"

class Cross : public Piece{
public:
    Cross(ColorOfPieces color);
    ~Cross() noexcept override;
    trajectory drawTraject(Position const &, bool) override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CPP_CHESSGAME_CROSS_H
