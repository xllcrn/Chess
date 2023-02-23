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
    Piece();
    Piece(char, ColorOfPieces, Position);
    Piece(Piece const &);
    Piece(Piece const &&);
    char getType() const;
    Position const & getPosition() const;
    std::string to_String();
    Piece& operator=(Piece const &);
    Piece& operator=(Piece const &&);
    bool isValid(Position const &);
    void Piece::setPosition(Position const &);
private:
    char m_type;
    ColorOfPieces m_color;
    Position m_position;
};
std::ostream& operator<<(std::ostream& , Piece &);

#endif //CHESS_PIECE_H
