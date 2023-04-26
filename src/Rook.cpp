#include "Rook.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Rook::Rook(Color color):Piece('r',color, 5){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Rook::~Rook() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard Rook::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return (verticalMove(pos, 8, bb2) | horizontalMove(pos, 8, bb2) );
}

bool Rook::isRook() const{
    return true;
}

bool Rook::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos==Position::create('a',1)) return true;
            if(pos==Position::create('h',1)) return true;
            break;
        case(Color::BLACK):
            if(pos==Position::create('a',8)) return true;
            if(pos==Position::create('h',8)) return true;
            break;
    }
    return false;
}