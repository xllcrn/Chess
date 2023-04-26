#include "Cross.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Cross::Cross(Color color):Piece('x',color, 0){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Cross::~Cross() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
Bitboard Cross::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    return 0;
}

bool Cross::isInitialPosition(Position const & pos) const{
    return true;
}