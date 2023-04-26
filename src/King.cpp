//
// Created by xllcr on 23/02/2023.
//
#include "King.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

King::King(Color color):Piece('k',color, 0){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
King::~King() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard King::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return (verticalMove(pos, 1, bb2) | horizontalMove(pos, 1, bb2) |
            diagonalMove(pos, 1, bb2));
}


bool King::isKing() const{
    return true;
}

bool King::isKingW() const{
    if (m_color==Color::WHITE)
        return true;
    else
        return false;
}

bool King::isKingB() const{
    if (m_color==Color::BLACK)
        return true;
    else
        return false;
}

bool King::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos==Position::create('e',1)) return true;
            break;
        case(Color::BLACK):
            if(pos==Position::create('e',8)) return true;
            break;
    }
    return false;
}
