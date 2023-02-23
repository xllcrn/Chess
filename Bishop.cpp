//
// Created by xllcr on 23/02/2023.
//

#include "Bishop.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Bishop::Bishop(ColorOfPieces color):Piece('b',color){}

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