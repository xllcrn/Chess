//
// Created by xllcr on 22/02/2023.
//

#include "Pawn.h"
#include <set>

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/
Pawn::Pawn(ColorOfPieces color):Piece('p',color,1){
}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Pawn::~Pawn() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Pawn::isValid(Position const & posBefore, Position const & posAfter){
    return true;
}

trajectory Pawn::drawTraject(Position const & posStart){
    trajectory traject;
    trajectory vert;
    auto step = 1;
    if(!m_hasMoved) step=2;
    vert = (*this).Piece::vertical(posStart, step);

    for (path const & path1: vert){
        Position pos = path1[0];
        switch (m_color){
            case(ColorOfPieces::WHITE):
                if (pos.getY()>posStart.getY()) traject.insert(path1);
                break;
            case(ColorOfPieces::BLACK):
                if (pos.getY()<posStart.getY()) traject.insert(path1);
                break;
        }
    }
    return traject;
}
