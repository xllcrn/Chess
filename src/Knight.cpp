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
trajectory Knight::drawTraject(Position const & posStart, bool b1, bool b2){
    trajectory traject;
    trajectory ltraj;
    ltraj = lDisplacement(posStart);
    traject.insert(ltraj.begin(),ltraj.end());
    return traject;
}

bool Knight::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos==Position::create_position('b',8)) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos==Position::create_position('b',1)) return true;
            break;
    }
    return false;
}