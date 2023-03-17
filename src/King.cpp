//
// Created by xllcr on 23/02/2023.
//

#include "King.h"

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

King::King(ColorOfPieces color):Piece('k',color, 0){}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
King::~King() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
trajectory King::drawTraject(Position const & posStart, bool b1){
    trajectory traject;
    trajectory vert, hori, diag;
    auto step = 1;
    vert = vertical(posStart, step);
    hori = horizontal(posStart, step);
    diag = diagonal(posStart, step);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    traject.insert(diag.begin(),diag.end());
    return traject;
}

bool King::isKing() const{
    return true;
}

bool King::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos==Position::create_position('e',1)) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos==Position::create_position('e',8)) return true;
            break;
    }
    return false;
}
