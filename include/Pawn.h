#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color);
    ~Pawn() noexcept override;
    Bitboard potentialBitMove(int const &, tuplBitboard const &) const override;
    bool isPromoted(Position const &) const override;
    bool isInitialPosition(Position const & pos) const override;
    bool isInitialPosition(int const & pos) const;
private:
    bool isPieceFront(int const & pos, int const & step, tuplBitboard const& bb2, Color const & )const;
};

#endif //CHESS_PAWN_H
