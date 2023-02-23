//
// Created by xllcr on 23/02/2023.
//

#include "King.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

King::King(ColorOfPieces color):Piece('k',color){}

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