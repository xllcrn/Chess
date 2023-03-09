//
// Created by xllcr on 22/02/2023.
//


#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "Position.h"
#include <vector>
#include <set>

/// @brief Color of chessboard pieces
enum class ColorOfPieces
{
    WHITE=1,        ///< White
    BLACK=2,        ///< Black
    MAX_COLOR=3     ///< -
};

using path = std::vector<Position>;
using trajectory = std::set<path> ;

/// @brief Abstract & base class for chessboard pieces
/// @details Draw allowable trajectory for displacement
/// and give access to some attributes
class Piece {
public:
    // constructors
    Piece(char, ColorOfPieces, int);
    virtual ~Piece() noexcept = default;
    // member methods
    std::string to_String() const;
    virtual trajectory drawTraject(Position const &, bool, bool=false)=0;
    //getter/setter
    char getType() const;
    int getValue() const;
    virtual bool isKing() const;
    virtual bool isPromoted(Position const &) const;
    ColorOfPieces getColor() const;
    virtual bool isInitialPosition(Position const &) const=0;
protected:
    trajectory vertical(Position const &, int step=8) const;
    trajectory horizontal(Position const &, int step=8) const;
    trajectory diagonal(Position const &, int step=8) const;
    trajectory lDisplacement(Position const &, int step=8) const;
    char m_type;
    int m_value;
    ColorOfPieces m_color;
};
std::ostream& operator<<(std::ostream& , Piece &);
std::ostream& operator<<(std::ostream& , ColorOfPieces &);
#endif //CHESS_PIECE_H
