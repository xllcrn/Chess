#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"

class Knight : public Piece{
public:
    Knight(Color color);
    ~Knight() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CHESS_KNIGHT_H
