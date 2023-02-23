//
// Created by xllcr on 23/02/2023.
//

#include "Queen.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Queen::Queen(ColorOfPieces color):Piece('q',color){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Queen::~Queen() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Queen::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}