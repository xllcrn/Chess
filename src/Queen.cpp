#include "Queen.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Queen::Queen(Color color):Piece('q',color, 9){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Queen::~Queen() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard Queen::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return (verticalMove(pos, 8, bb2) | horizontalMove(pos, 8, bb2) |
            diagonalMove(pos, 8, bb2));
}

bool Queen::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos==Position::create('d',1)) return true;
            break;
        case(Color::BLACK):
            if(pos==Position::create('d',8)) return true;
            break;
    }
    return false;
}