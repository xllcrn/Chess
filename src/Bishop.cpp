//
// Created by xllcr on 23/02/2023.
//

#include "Bishop.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Bishop::Bishop(Color color):Piece('b',color,3){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Bishop::~Bishop() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard Bishop::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return diagonalMove(pos, 8, bb2);
}

bool Bishop::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos==Position::create('c',1)) return true;
            if(pos==Position::create('f',1)) return true;
            break;
        case(Color::BLACK):
            if(pos==Position::create('c',8)) return true;
            if(pos==Position::create('f',8)) return true;
            break;
    }
    return false;
}
