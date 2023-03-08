//
// Created by xllcr on 23/02/2023.
//

#include "Bishop.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Bishop::Bishop(ColorOfPieces color):Piece('b',color,3){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Bishop::~Bishop() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Bishop::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}

trajectory Bishop::drawTraject(Position const & posStart, bool){
    trajectory traject;
    trajectory diag;
    diag = diagonal(posStart);
    traject.insert(diag.begin(),diag.end());
    return traject;
}

