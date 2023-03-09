//
// Created by xllcr on 23/02/2023.
//

#include "Rook.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Rook::Rook(ColorOfPieces color):Piece('r',color, 5){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Rook::~Rook() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
trajectory Rook::drawTraject(Position const & posStart, bool){
    trajectory traject;
    trajectory vert, hori, diag;
    vert = vertical(posStart);
    hori = horizontal(posStart);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    return traject;
}
