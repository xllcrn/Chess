#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"

class Queen : public Piece{
public:
    Queen(Color color);
    ~Queen() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isInitialPosition(Position const & pos) const override;
private:
};


#endif //CHESS_QUEEN_H
