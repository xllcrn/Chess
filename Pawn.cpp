//
// Created by xllcr on 22/02/2023.
//

#include "Pawn.h"
#include <set>

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/
Pawn::Pawn(ColorOfPieces color):Piece('p',color),m_moved(false){
}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Pawn::~Pawn() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Pawn::isValid(Position const & posBefore, Position const & posAfter){

    int y_bf{posBefore.getY()};
    int y_af{posAfter.getY()};
    int step;
    switch(m_moved) {
        case true:
            step=1;
            break;
        case false:
            step=2;
            break;
    }

    // cannot move in diagonal
    if(posBefore.getX()!=posAfter.getX()) return false;
    // no more than the number of step
    if(abs(y_af-y_bf)>step) return false;
    // only forward
    switch(m_color) {
        case ColorOfPieces::WHITE:
            if(y_af<=y_bf) return false;
            break;
        case ColorOfPieces::BLACK:
            if(y_bf<=y_af) return false;
            break;
    }

//  except if it's for stealing
//  one or 2 steps
    m_moved = true;
    return true;
}