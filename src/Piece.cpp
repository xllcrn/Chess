//
// Created by xllcr on 22/02/2023.
//

#include <set>
#include "Piece.h"


/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/
Piece::Piece(char type, ColorOfPieces color, int value):
        m_type(type),m_color(color),m_value(value) {m_hasMoved=false;}

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/

std::string Piece::to_String() const {
    std::ostringstream ostr;
    std::string color;
    switch (m_color){
        case ColorOfPieces::WHITE:
            color = "white";
            break;
        case ColorOfPieces::BLACK:
            color = "black";
            break;
    }
    ostr << "Piece : \n";
    ostr << "  -   type     :" << m_type  << "\n";
    ostr << "  -   color    :" << color  << "\n";
    return ostr.str();
}

trajectory Piece::vertical(Position const & posStart, int step)const{
    path path1,path2;
    //vertical
    auto istep=0;
    for (auto i=posStart.getY()+1; i<9; i++){
        path1.push_back(Position::create_position(posStart.getX(),i));
        if (++istep==step) break;
    }
    istep=0;
    for (auto i=posStart.getY()-1; i>0; i--){
        path2.push_back(Position::create_position(posStart.getX(),i));
        if (++istep==step) break;
    }
    trajectory trajVert({path1,path2});
    return trajVert;
}

trajectory Piece::diagonal(Position const & posStart, int step) const{
    path diagA1,diagA2;
    path diagB1,diagB2;
    // diagA : from left to right
    auto i = posStart.getY();
    auto istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--) {
        if (i<8) {
            diagA1.push_back(Position::create_position(c, ++i));
            if (++istep==step) break;
        }
        else{break;}
    }
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()+1; c<='h'; c++) {
        if (i>1) {
            diagA2.push_back(Position::create_position(c, --i));
            if (++istep==step) break;
        }
        else{break;}
    }
    // diagB : from right to left
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()+1; c<='h'; c++){
        if (i<8) {
            diagB1.push_back(Position::create_position(c, ++i));
            if (++istep==step) break;
        }
        else{break;}
    }
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--){
        if (i>1) {
            diagB2.push_back(Position::create_position(c, --i));
            if (++istep==step) break;
        }
        else{break;}
    }

    trajectory trajVert({diagA1,diagA2,diagB1,diagB2});
    return trajVert;
}

trajectory Piece::horizontal(Position const & posStart, int step)const{
    path path1,path2;
    auto istep=0;
    //horizontal
    for (char c=posStart.getX()+1; c<='h'; c++){
        path1.push_back(Position::create_position(c,posStart.getY()));
        if (++istep==step) break;
    }
    istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--){
        path2.push_back(Position::create_position(c,posStart.getY()));
        if (++istep==step) break;
    }
    trajectory trajVert({path1,path2});
    return trajVert;
}

trajectory Piece::lDisplacement(Position const & posStart, int step)const{
    char c = posStart.getX();
    auto i = posStart.getY();
    auto iP1 = i+1;
    auto iP2 = i+2;
    auto iM1 = i-1;
    auto iM2 = i-2;
    char cM1 = c-1;
    char cM2 = c-2;
    char cP1 = c+1;
    char cP2 = c+2;
    trajectory trajL;

    try{
        Position pos = Position::create_position(cM1,iP2);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}
    try{
        Position pos = Position::create_position(cM1,iM2);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}

    try{
        Position pos = Position::create_position(cM2,iP1);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}
    try{
        Position pos = Position::create_position(cM2,iM1);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}

    try{
        Position pos = Position::create_position(cP1,iP2);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}
    try{
        Position pos = Position::create_position(cP1,iM2);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}

    try{
        Position pos = Position::create_position(cP2,iP1);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}
    try{
        Position pos = Position::create_position(cP2,iM1);
        trajL.insert(path {pos});
    }catch(const std::exception &e){}


    return trajL;
}

/* ----------------------------------------------------------
 *      SETTER/ GETTER
 * ----------------------------------------------------------*/

char Piece::getType() const{
    switch(m_color){
        case ColorOfPieces::BLACK:
            return toupper(m_type);
            break;
        case ColorOfPieces::WHITE:
            return tolower(m_type);
            break;
    }
}

int Piece::getValue() const{
    return m_value;
}

ColorOfPieces Piece::getColor() const{
    return m_color;
}

void Piece::setMoved() {
    m_hasMoved = true;
}

bool Piece::isKing() const{
    return false;
}

/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, Piece & p){
    os << p.to_String();
    return os;
}

std::ostream& operator<<(std::ostream& os, ColorOfPieces & color){
    switch(color){
        case ColorOfPieces::BLACK:
            os << "black";
            break;
        case ColorOfPieces::WHITE:
            os << "white";
            break;
    }
    return os;
}
