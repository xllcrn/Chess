//
// Created by xllcr on 23/02/2023.
//

#include "Queen.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Queen::Queen(ColorOfPieces color):Piece('q',color, 9){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Queen::~Queen() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
trajectory Queen::drawTraject(Position const & posStart, bool b1, bool b2){
    trajectory traject;
    trajectory vert, hori, diag;
    vert = vertical(posStart);
    hori = horizontal(posStart);
    diag = diagonal(posStart);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    traject.insert(diag.begin(),diag.end());
    return traject;
}

bool Queen::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos==Position::create_position('d',1)) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos==Position::create_position('d',8)) return true;
            break;
    }
    return false;
}