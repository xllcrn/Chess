//
// Created by xllcr on 22/02/2023.
//

#include "Piece.h"


/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

Piece::Piece():
        m_type('0'),m_color(ColorOfPieces::WHITE) {}

Piece::Piece(char type, ColorOfPieces color):
        m_type(type),m_color(color) {}

Piece::Piece(Piece const & p){
    m_type = p.m_type;
    m_color = p.m_color;
//    m_position = p.m_position;
}

// Constructeur de déplacement (move constructor)
Piece::Piece(Piece const && p){
    m_type = p.m_type;
    m_color = p.m_color;
//    m_position = p.m_position;
}

// opérateur= de déplacement (move assignment)
Piece& Piece::operator=(Piece const && p){
    if (this != &p){ // on déplace le même elt ?
        m_type = p.m_type;
        m_color = p.m_color;
//        m_position = p.m_position;
    }
    return *this; // on valide les changements
}

Piece& Piece::operator=(Piece const & p)
{
    m_type = p.m_type;
    m_color = p.m_color;
//    m_position = p.m_position;
    return *this;
}

/* ----------------------------------------------------------
 *      DESTRUCTOR
 * ----------------------------------------------------------*/
Piece::~Piece() noexcept{};

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/

std::string Piece::to_String() {
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
//    ostr << "  -   position :" << m_position  << "\n";
    return ostr.str();
}

/* ----------------------------------------------------------
 *      SETTER/ GETTER
 * ----------------------------------------------------------*/
//Position const & Piece::getPosition() const{
//    return m_position ;
//}
//void Piece::setPosition(Position const &p) {
//    m_position = p ;
//}

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
void Piece::setType(char const & type) {
    m_type = type ;
}

/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, Piece & p){
    os << p.to_String();
    return os;
}