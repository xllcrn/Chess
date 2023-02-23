//
// Created by xllcr on 23/02/2023.
//

#include "Knight.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Knight::Knight(ColorOfPieces color):Piece('h',color){}

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