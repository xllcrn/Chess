//
// Created by xllcr on 23/02/2023.
//

#include "Queen.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Queen::Queen(ColorOfPieces color):Piece('q',color, 9){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Queen::~Queen() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Queen::isValid(Position const & posBefore, Position const & posAfter){
    if(posBefore==posAfter) return false;

    return true;
}

trajectory Queen::drawTraject(Position const & posStart){
    trajectory traject;
    trajectory vert, hori, diag;
    vert = vertical(posStart);
    hori = horizontal(posStart);
    diag = diagonal(posStart);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    traject.insert(diag.begin(),diag.end());
    return traject;
}
