//
// Created by xllcr on 21/02/2023.
//

#include "Position.h"

Position::Position():m_line('0'),m_column(0){}

Position::Position(char const & x,int const &y):m_line(x),m_column(y){
    /* Convert position to coordinate into vector m_board */
    int lin = x-97;
    m_coord = (y-1)*8+lin;
}

Position::Position(Position const & pos){
    m_line = pos.m_line;
    m_column = pos.m_column;
    m_coord = pos.m_coord;
}

Position::~Position(){}

Position & Position::operator=(Position const &pos){
    m_line = pos.m_line;
    m_column = pos.m_column;
    return *this;
}


std::ostream& operator<<(std::ostream& os, Position & pos){
    os << pos.to_String();
    return os;
}

std::string Position::to_String() {
    std::ostringstream ostr;
    ostr << "(" << m_line << "," << m_column << ") \n";
    return ostr.str();
}

void Position::setX(char const &x){
    m_line = x;
}
char const & Position::getX() const{
    return m_line ;
}

void Position::setY(int const &y){
    m_column = y;
}
int const & Position::getY() const{
    return m_column ;
}

void Position::setCoord(int const &coord){
    m_coord = coord;
}
int const & Position::getCoord() const{
    return m_coord ;
}

Position new_position(Position const & pos, Direction const & dir){
    Position new_pos(pos);
    int x(pos.getX()),y(pos.getY());
    switch (dir) {
        case haut:
            new_pos.setY(--y);
            break;
        case bas:
            new_pos.setY(++y);
            break;
        case gauche:
            new_pos.setX(--x);
            break;
        case droite:
            new_pos.setX(++y);
            break;
        default:
            break;
    }
    return new_pos;
}

bool operator==(Position& pFirst, Position & pSecond){
    return (pFirst.getX()==pSecond.getX() && pFirst.getY()==pSecond.getY());
}
bool operator!=(Position& pFirst, Position & pSecond){
    return (!(pFirst==pSecond));
}
bool operator<(const Position& pFirst, const Position & pSecond){
    return (pFirst.getCoord()<pSecond.getCoord());
}