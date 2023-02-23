//
// Created by xllcr on 22/02/2023.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "Position.h"
enum class ColorOfPieces
{
    WHITE=1,
    BLACK=2,
    MAX_COLOR=3
};

class Piece {
public:
    // constructors
    Piece();
    Piece(char, ColorOfPieces);
    Piece(Piece const &);
    Piece(Piece const &&);
    Piece& operator=(Piece const &);
    Piece& operator=(Piece const &&);
    virtual ~Piece() noexcept;
    // member methods
    std::string to_String();
    virtual bool isValid(Position const &,Position const &)=0;
    //getter/setter
//    Position const & getPosition() const;
    char getType() const;
    void setType(char const &) ;
//    void setPosition(Position const &);
protected:
    char m_type;
    ColorOfPieces m_color;
//    Position m_position;
};
std::ostream& operator<<(std::ostream& , Piece &);

#endif //CHESS_PIECE_H
