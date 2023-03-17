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