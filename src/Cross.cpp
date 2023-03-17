//
// Created by xllcr on 14/03/2023.
//

#include "Cross.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Cross::Cross(ColorOfPieces color):Piece('x',color, 0){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Cross::~Cross() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
trajectory Cross::drawTraject(Position const & posStart, bool b1){
    trajectory traject;
    return traject;
}

bool Cross::isInitialPosition(Position const & pos) const{
    return true;
}