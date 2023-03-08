//
// Created by xllcr on 23/02/2023.
//

#include "Knight.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Knight::Knight(ColorOfPieces color):Piece('h',color, 3){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Knight::~Knight() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Knight::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}

trajectory Knight::drawTraject(Position const & posStart, bool){
    trajectory traject;
    trajectory ltraj;
    ltraj = lDisplacement(posStart);
    traject.insert(ltraj.begin(),ltraj.end());
    return traject;
}

