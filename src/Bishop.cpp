//
// Created by xllcr on 23/02/2023.
//

#include "Bishop.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Bishop::Bishop(ColorOfPieces color):Piece('b',color,3){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Bishop::~Bishop() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
trajectory Bishop::drawTraject(Position const & posStart, bool b1, bool b2){
    trajectory traject;
    trajectory diag;
    diag = diagonal(posStart);
    traject.insert(diag.begin(),diag.end());
    return traject;
}

bool Bishop::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos==Position::create_position('c',1)) return true;
            if(pos==Position::create_position('f',1)) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos==Position::create_position('c',8)) return true;
            if(pos==Position::create_position('f',8)) return true;
            break;
    }
    return false;
}
