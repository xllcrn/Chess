#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"
class King :public Piece {
public:
    King(Color color);
    ~King() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isKing() const override;
    bool isInitialPosition(Position const & pos) const override;
    bool isKingW() const;
    bool isKingB() const;
private:
};


#endif //CHESS_KING_H
