#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"
class Rook : public Piece{
public:
    Rook(Color color);
    ~Rook() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isInitialPosition(Position const & pos) const override;
    bool isRook() const override;
private:
};


#endif //CHESS_ROOK_H
