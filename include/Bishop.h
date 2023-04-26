#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"
class Bishop : public Piece{
public:
    Bishop(Color color);
    ~Bishop() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CHESS_BISHOP_H
