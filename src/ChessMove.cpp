//
// Created by xllcr on 10/03/2023.
//

#include "ChessMove.h"

/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, ChessMove const & move){
    os << move.piece_type << move.start_pos << "->" << move.end_pos;
    return os;
}


Move::Move(int const & startPos, int const & endPos) : start_pos(startPos), end_pos(endPos) {}

Move::Move(Position const & startPos, Position const & endPos) : start_pos(startPos.getIndex()), end_pos(endPos.getIndex()) {}

Move reverse(Move const & move){
    Move moveReversed(move);
    std::swap(moveReversed.start_pos,moveReversed.end_pos);
    return moveReversed;
}

bool operator==(Move const & moveLeft, Move const & moveRight){
    return (moveLeft.start_pos==moveRight.start_pos)&&(moveLeft.end_pos==moveRight.end_pos);
}
