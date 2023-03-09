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
trajectory Pawn::drawTraject(Position const & posStart,bool hasMoved, bool move_diag){
    trajectory traject;
    trajectory traj;
    // if has moved : step 1, if not can be 2
    auto step = 1;
    if (move_diag){
        traj = diagonal(posStart, step);
    }
    else{
        if(!hasMoved) step=2;
        traj = vertical(posStart, step);
    }

    // only moving forward
    for (path const & path1: traj){
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

bool Pawn::isPromoted(Position const &pos) const {
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos.getY()==8) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos.getY()==1) return true;
            break;
    }
    return false;
}

bool Pawn::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(ColorOfPieces::WHITE):
            if(pos.getY()==2) return true;
            break;
        case(ColorOfPieces::BLACK):
            if(pos.getY()==7) return true;
            break;
    }
    return false;
}


/* ------------------------------------------------------------------------
 *                        GETTER / SETTER
/* ------------------------------------------------------------------------ */
