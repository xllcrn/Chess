//
// Created by xllcr on 22/02/2023.
//

#include "Pawn.h"
#include <set>

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/
Pawn::Pawn(Color color):Piece('p',color,1){
}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Pawn::~Pawn() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
bool Pawn::isPieceFront(int const & pos, int const & front, tuplBitboard const& bb2, Color const & pieceColor)const {
    const auto&[bbW, bbB] = bb2;
    auto indexFront{0};
    if (m_color == Color::WHITE) indexFront = pos + front;
    if (m_color == Color::BLACK) indexFront = pos - front;
    int bitResult{0};
    if (pieceColor==Color::ANYCOLOR){
        bitResult = getBit(bbW, indexFront) + getBit(bbB, indexFront);
    }
    else {
        if (m_color == Color::WHITE) bitResult = getBit(bbB, indexFront);
        if (m_color == Color::BLACK) bitResult = getBit(bbW, indexFront);
    }
    return bitResult >= 1;
}

Bitboard Pawn::potentialBitMove(int const & pos, tuplBitboard const& bb2)const{
    auto[bbW,bbB] = bb2;
    // is there a piece in front?
    auto isPieceFront1 = isPieceFront(pos,bitVertical1,bb2,Color::ANYCOLOR);
    Bitboard bitboard1{0};
    if (!isPieceFront1) bitboard1 = verticalMove(pos, 1, bb2);

    auto isPieceFront2 = isPieceFront(pos,bitVertical2,bb2,Color::ANYCOLOR);
    Bitboard bitboard2{0};
    if (isInitialPosition(pos) && !isPieceFront1 && !isPieceFront2) bitboard2 = verticalMove(pos, 2, bb2);

    auto isPieceDiagA = isPieceFront(pos,bitDiagonalA,bb2, Color::ALTERNATE);
    auto isPieceDiagB = isPieceFront(pos,bitDiagonalB,bb2, Color::ALTERNATE);
    Bitboard bitboard3{0};
    if (isPieceDiagA) bitboard3 = (bitboard3 | diagonalMoveA(pos, 1, bb2));
    if (isPieceDiagB) bitboard3 = (bitboard3 | diagonalMoveB(pos, 1, bb2));

    Bitboard bitboard = (bitboard1 | bitboard2 | bitboard3);

    Bitboard bitForward{0};
    switch (m_color){
        case(Color::WHITE):
            for (auto i=pos;i<8*sizeof(Bitboard);i++) {bitForward = setBit(bitForward, i);}
            break;
        case(Color::BLACK):
            for (auto i=pos;i>0;i--) {bitForward = setBit(bitForward, i);}
            break;
    }
    return bitForward & bitboard;
}


bool Pawn::isPromoted(Position const &pos) const {
    switch (m_color){
        case(Color::WHITE):
            if(pos.getY()==8) return true;
            break;
        case(Color::BLACK):
            if(pos.getY()==1) return true;
            break;
    }
    return false;
}

bool Pawn::isInitialPosition(Position const & pos) const{
    switch (m_color){
        case(Color::WHITE):
            if(pos.getY()==2) return true;
            break;
        case(Color::BLACK):
            if(pos.getY()==7) return true;
            break;
    }
    return false;
}
bool Pawn::isInitialPosition(int const & index) const{
    switch (m_color){
        case(Color::WHITE):
            if((1+index/8)==2) return true;
            break;
        case(Color::BLACK):
            if((1+index/8)==7) return true;
            break;
    }
    return false;
}

/* ------------------------------------------------------------------------
 *                        GETTER / SETTER
/* ------------------------------------------------------------------------ */
