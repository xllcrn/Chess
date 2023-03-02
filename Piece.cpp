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

//trajectory Piece::vertical(Position const & posStart,Position const & posEnd)const{
//    path path1;
//    //vertical
//    if(posStart.getX()==posEnd.getX()){
//        if(posStart.getY()<posEnd.getY()) {
//            for (auto i=posStart.getY()+1; i<=posEnd.getY(); i++){
//                path1.push_back({posStart.getX(),i});
//            }
//        }
//        else{
//            for (auto i=posStart.getY()-1; i<=posEnd.getY(); i--){
//                path1.push_back({posStart.getX(),i});
//            }
//        }
//    }
//    trajectory trajVect({path1});
//    return trajVect;
//}

trajectory Piece::vertical(Position const & posStart, int const & step)const{
    path path1,path2;
    //vertical
    auto istep=0;
    for (auto i=posStart.getY()+1; i<9; i++){
        path1.push_back({posStart.getX(),i});
        if (++istep==step) break;
    }
    istep=0;
    for (auto i=posStart.getY()-1; i>0; i--){
        path2.push_back({posStart.getX(),i});
        if (++istep==step) break;
    }
    trajectory trajVert({path1,path2});
    return trajVert;
}

trajectory Piece::diagonal(Position const & posStart, int const & step) const{
    path diagA1,diagA2;
    path diagB1,diagB2;
    // diagA : from left to right
    auto i = posStart.getY();
    auto istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--) {
        if (i<8) {
            diagA1.push_back({c, ++i});
            if (++istep==step) break;
        }
        else{break;}
    }
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()+1; c<='h'; c++) {
        if (i>1) {
            diagA2.push_back({c, --i});
            if (++istep==step) break;
        }
        else{break;}
    }
    // diagB : from right to left
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()+1; c<='h'; c++){
        if (i<8) {
            diagB1.push_back({c, ++i});
            if (++istep==step) break;
        }
        else{break;}
    }
    i = posStart.getY();
    istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--){
        if (i>1) {
            diagB2.push_back({c, --i});
            if (++istep==step) break;
        }
        else{break;}
    }

    trajectory trajVert({diagA1,diagA2,diagB1,diagB2});
    return trajVert;
}

//trajectory Piece::horizontal(Position const & posStart,Position const & posEnd)const{
//    path path1;
//    //horizontal
//    if(posStart.getY()==posEnd.getY()){
//        if(posStart.getX()<posEnd.getX()) {
//            for (char c=posStart.getX()+1; c<=posEnd.getX(); c++){
//                path1.push_back({c,posStart.getY()});
//            }
//        }
//        else{
//            for (char c=posStart.getX()-1; c<=posEnd.getX(); c--){
//                path1.push_back({c,posStart.getY()});
//            }
//        }
//    }
//    trajectory trajHori({path1});
//    return trajHori;
//}

trajectory Piece::horizontal(Position const & posStart, int const & step)const{
    path path1,path2;
    auto istep=0;
    //horizontal
    for (char c=posStart.getX()+1; c<='h'; c++){
        path1.push_back({c,posStart.getY()});
        if (++istep==step) break;
    }
    istep=0;
    for (char c=posStart.getX()-1; c>='a'; c--){
        path2.push_back({c,posStart.getY()});
        if (++istep==step) break;
    }
    trajectory trajVert({path1,path2});
    return trajVert;
}

trajectory Piece::lDisplacement(Position const & posStart, int const & step)const{
    char c = posStart.getX();
    auto i = posStart.getY();
    auto jP1 = i+1;
    auto jP2 = i+2;
    auto jM1 = i-1;
    auto jM2 = i-2;
    trajectory trajL;

    if ('a'<=(c-1) && (c-1)<='h'){
        if (1<=jP2 && jP2<=8) trajL.insert(path {Position {c-1,jP2}});
        if (1<=jM2 && jM2<=8) trajL.insert(path {Position {c-1,jM2}});
    }

    if ('a'<=(c-2) && (c-2)<='h'){
        if (1<=jP1 && jP1<=8) trajL.insert(path {Position {c-2,jP1}});
        if (1<=jM1 && jM1<=8) trajL.insert(path {Position {c-2,jM1}});
    }

    if ('a'<=(c+1) && (c+1)<='h'){
        if (1<=jP2 && jP2<=8) trajL.insert(path {Position {c+1,jP2}});
        if (1<=jM2 && jM2<=8) trajL.insert(path {Position {c+1,jM2}});
    }

    if ('a'<=(c+2) && (c+2)<='h'){
        if (1<=jP1 && jP1<=8) trajL.insert(path {Position {c+2,jP1}});
        if (1<=jM1 && jM1<=8) trajL.insert(path {Position {c+2,jM1}});
    }
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