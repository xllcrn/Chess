//
// Created by xllcr on 23/02/2023.
//

#include "Rook.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Rook::Rook(ColorOfPieces color):Piece('r',color){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Rook::~Rook() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Rook::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}