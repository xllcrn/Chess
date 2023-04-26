#pragma once
#include "Piece.h"

class Cross : public Piece{
public:
    Cross(Color color);
    ~Cross() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isInitialPosition(Position const & pos) const override;
private:
};

