//
// Created by xllcr on 10/03/2023.
//

#ifndef CPP_CHESSGAME_CHESSMOVE_H
#define CPP_CHESSGAME_CHESSMOVE_H

#include <Position.h>
#include "Piece.h"

// structure to store moves
struct ChessMove {
    ChessMove(Position const & posB, Position const &  posA, char c):start_pos(posB),end_pos(posA),piece_type(c){};
    Position start_pos;
    Position end_pos;
    char piece_type;
};

std::ostream& operator<<(std::ostream&, ChessMove const &);

#endif //CPP_CHESSGAME_CHESSMOVE_H
