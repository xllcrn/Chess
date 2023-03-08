//
// Created by xllcr on 22/02/2023.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "Position.h"
#include <vector>
#include <set>
enum class ColorOfPieces
{
    WHITE=1,
    BLACK=2,
    MAX_COLOR=3
};

using path = std::vector<Position>;
using trajectory = std::set<path> ;

class Piece {
public:
    // constructors
    Piece(char, ColorOfPieces, int);
    virtual ~Piece() noexcept = default;
    // member methods
    std::string to_String() const;
    virtual bool isValid(Position const &,Position const &)=0;
    virtual trajectory drawTraject(Position const &, bool=false)=0;
    //getter/setter
    char getType() const;
    int getValue() const;
    ColorOfPieces getColor() const;
    void setMoved();
    virtual void setDiagonal(bool move_diag);
protected:
    trajectory vertical(Position const &, int step=8) const;
    trajectory horizontal(Position const &, int step=8) const;
    trajectory diagonal(Position const &, int step=8) const;
    trajectory lDisplacement(Position const &, int step=8) const;
    char m_type;
    int m_value;
    ColorOfPieces m_color;
    bool m_hasMoved;
};
std::ostream& operator<<(std::ostream& , Piece &);
std::ostream& operator<<(std::ostream& , ColorOfPieces &);
#endif //CHESS_PIECE_H
