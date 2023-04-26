#include <set>
#include "Piece.h"
#include <cmath>
/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/
Piece::Piece(char type, Color color, int value):
        m_type(type),m_color(color),m_value(value){}

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
std::string Piece::to_String() const {
    std::ostringstream ostr;
    std::string color;
    switch (m_color){
        case Color::WHITE:
            color = "white";
            break;
        case Color::BLACK:
            color = "black";
            break;
    }
    ostr << "Piece : \n";
    ostr << "  -   type     :" << m_type  << "\n";
    ostr << "  -   color    :" << color  << "\n";
    return ostr.str();
}

std::tuple<bool,bool> Piece::isIndexValid(int const index, Bitboard bbW, Bitboard bbB) const {
    auto indexValid = true;
    auto continueLoop = true;
    if (index<0 || index > 63) {indexValid = false;continueLoop =false;}
    if (indexValid) {
        auto isPieceW = getBit(bbW,index)==1;
        auto isPieceB = getBit(bbB,index)==1;
        // no piece at position index
        if(!isPieceW && !isPieceB) {indexValid = true;continueLoop = true;}
        if((m_color==Color::WHITE && isPieceW)||(m_color==Color::BLACK && isPieceB)) {
            indexValid = false;
            continueLoop = false;
        }
        if ((m_color==Color::WHITE && isPieceB)||(m_color==Color::BLACK && isPieceW)){
            indexValid = true;
            continueLoop = false;
        }
    }
    return std::make_tuple(indexValid,continueLoop);
}

Bitboard Piece::bitMove(int const & index, int const & bitStep, int const & step,
                        tuplBitboard const & bb2,
                        int const & stepLeft,
                        int const & stepRight) const{
    Bitboard bitboard=0;
    const auto&[bbW, bbB] = bb2;

    auto indexUp = index;
    for (auto i=1; i<=std::min(stepRight,step); i++) {
        indexUp += bitStep;
        auto[indexValidUp, continueUp] = isIndexValid(indexUp, bbW, bbB);
        if (indexValidUp) bitboard = setBit(bitboard, indexUp);
        if (!continueUp) break;
    }

    auto indexDown = index;
    for (auto i=1; i<=std::min(stepLeft,step); i++) {
        indexDown -= bitStep;
        auto[indexValidDown, continueDown] = isIndexValid(indexDown, bbW, bbB);
        if (indexValidDown) bitboard = setBit(bitboard, indexDown);
        if (!continueDown) break;
    }
    return bitboard;
}


Bitboard Piece::verticalMove(int const & index, int const & step, tuplBitboard const & bb2) const{
    auto stepLeft = index/8;
    auto stepRight = 8-stepLeft-1;
    return bitMove(index, bitVertical1,step, bb2, stepLeft, stepRight);
}

Bitboard Piece::horizontalMove(int const & index, int const & step,  tuplBitboard const & bb2) const{
    auto stepLeft = index%8;
    auto stepRight = 8-stepLeft-1;
    return bitMove(index, bitHorizontal,step, bb2, stepLeft, stepRight);
}

Bitboard Piece::diagonalMove(int const & index, int const & step, tuplBitboard const & bb2) const{
    std::cout << std::endl;
    return diagonalMoveA(index,step,bb2)|diagonalMoveB(index,step,bb2);
}

Bitboard Piece::diagonalMoveA(int const & index, int const & step, tuplBitboard const & bb2) const{
    auto i = index%8+1;
    auto j = index/8+1;
    int stepRight, stepLeft;
    if ((i+j)<10){
        auto tot = i +j -1;
        stepRight = index%8;
        stepLeft = tot - stepRight-1;
    }
    else{
        auto tot = (8-i) + (8-j) +1;
        stepLeft  = 8-i;
        stepRight = tot - stepLeft - 1;
    }
    return bitMove(index, bitDiagonalA,step, bb2, stepLeft, stepRight);
}

Bitboard Piece::diagonalMoveB(int const & index, int const & step, tuplBitboard const & bb2) const{
    auto i = index%8+1;
    auto j = index/8+1;
    int stepRight, stepLeft;
    if (i<=j){
        auto tot = (8-j) + i;
        stepLeft = index%8;
        stepRight = tot - stepLeft-1;
    }
    else{
        auto tot = (8-i) + j;
        stepRight = 8-i;
        stepLeft = tot - stepRight - 1;
    }
    return bitMove(index, bitDiagonalB,step, bb2, stepLeft, stepRight);
}

Bitboard Piece::lMove(int const & index, tuplBitboard const & bb2) const {
    return (bitMove(index, bitLMoveA,1, bb2, 1, 1) | bitMove(index, bitLMoveB,1,bb2, 1, 1) |
            bitMove(index, bitLMoveC,1, bb2, 1, 1) | bitMove(index, bitLMoveD,1, bb2, 1, 1) );
}

/* ----------------------------------------------------------
 *      SETTER/ GETTER
 * ----------------------------------------------------------*/

char Piece::getType() const{
    switch(m_color){
        case Color::BLACK:
            return toupper(m_type);
            break;
        case Color::WHITE:
            return tolower(m_type);
            break;
    }
}

int Piece::getValue() const{
    return m_value;
}

Color Piece::getColor() const{
    return m_color;
}

bool Piece::isKing() const{
    return false;
}
bool Piece::isKingW() const{
    return false;
}
bool Piece::isKingB() const{
    return false;
}
bool Piece::isRook() const{
    return false;
}

bool Piece::isPromoted(Position const & pos) const{
    return false;
}
/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, Piece & p){
    os << p.to_String();
    return os;
}

std::ostream& operator<<(std::ostream& os, Color const & color){
    switch(color){
        case Color::BLACK:
            os << "black";
            break;
        case Color::WHITE:
            os << "white";
            break;
        case Color::NOCOLOR:
            os << "no color";
            break;
        case Color::ANYCOLOR:
            os << "any color";
            break;
    }
    return os;
}
