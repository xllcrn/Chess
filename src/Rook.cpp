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
trajectory Rook::drawTraject(Position const & posStart, bool b1, bool b2){
    trajectory traject;
    trajectory vert, hori, diag;
    vert = vertical(posStart);
    hori = horizontal(posStart);
    traject.insert(vert.begin(),vert.end());
    traject.insert(hori.begin(),hori.end());
    return traject;
}

bool Rook::isRook() const{
    return true;
}

bool Rook::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos==Position::create_position('a',1)) return true;
            if(pos==Position::create_position('h',1)) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos==Position::create_position('a',8)) return true;
            if(pos==Position::create_position('h',8)) return true;
            break;
    }
    return false;
}