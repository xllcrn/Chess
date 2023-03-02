//
// Created by xllcr on 23/02/2023.
//

#include "King.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

King::King(ColorOfPieces color):Piece('k',color, 0){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
King::~King() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool King::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}

trajectory King::drawTraject(Position const & posStart){
    trajectory traject;
    trajectory vert, hori, diag;
    auto step = 1;
    vert = (*this).Piece::vertical(posStart, step);
    hori = (*this).Piece::horizontal(posStart, step);
    diag = (*this).Piece::diagonal(posStart, step);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    traject.insert(diag.begin(),diag.end());
    return traject;
}
