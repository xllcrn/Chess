//
// Created by xllcr on 21/02/2023.
//
#include <cassert>
#include "Position.h"

/* ------------------------------------------------------------------------
 *                        CONSTRUCTOR
/* ------------------------------------------------------------------------ */

Position::Position(char const & x,unsigned int const &y):m_line(validate_line(x)),m_column(validate_column(y)){
//    int lettre=x;
//    assert(lettre>96 && lettre<105 && "Letter is not conform : should be between a and h included");
//    assert(y>0 && y<9 && "Number is not conform : should be between 1 and 8 included");
}


/* ------------------------------------------------------------------------
 *                        MEMBER FUNCTIONS
/* ------------------------------------------------------------------------ */

const char& Position::validate_line(const char& line)
{
    if (line < 'a' || line > 'h')
        throw std::runtime_error("line not valid");
    return line;
}

const unsigned int& Position::validate_column(const unsigned int& column)
{
    if (column < 1 || column > 8)
        throw std::runtime_error("column not valid");
    return column;
}

std::string Position::to_String() const {
    std::ostringstream ostr;
    ostr << "(" << m_line << "," << m_column << ") \n";
    return ostr.str();
}


/* ------------------------------------------------------------------------
 *                        GETTER / SETTER
/* ------------------------------------------------------------------------ */

void Position::setX(char const &x){
    m_line = x;
}
char const & Position::getX() const{
    return m_line ;
}

void Position::setY(unsigned int const &y){
    m_column = y;
}
unsigned int const & Position::getY() const{
    return m_column ;
}

int Position::getCoord() const{
    /* Convert position to coordinate into vector m_board */
    int lin = m_line-97;
    return (m_column-1)*8+lin;
}

/* ------------------------------------------------------------------------
 *                        EXTERNAL FUNCTIONS
/* ------------------------------------------------------------------------ */

std::ostream& operator<<(std::ostream& os, Position const & pos){
    os << pos.to_String();
    return os;
}

bool operator==(Position const & pFirst, Position const & pSecond){
    return (pFirst.getX()==pSecond.getX() && pFirst.getY()==pSecond.getY());
}
bool operator!=(Position const & pFirst, Position const & pSecond){
    return (!(pFirst==pSecond));
}
bool operator<(Position const & pFirst,Position const & pSecond){
    return (pFirst.getCoord()<pSecond.getCoord());
}
