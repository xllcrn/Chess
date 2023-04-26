#include "Knight.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Knight::Knight(Color color):Piece('h',color, 3){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Knight::~Knight() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard Knight::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return lMove(pos, bb2) ;
}


bool Knight::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos==Position::create('b',1)) return true;
            if(pos==Position::create('g',1)) return true;
            break;
        case(Color::BLACK):
            if(pos==Position::create('b',8)) return true;
            if(pos==Position::create('g',8)) return true;
            break;
    }
    return false;
}