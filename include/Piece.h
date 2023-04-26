#pragma once
#include "Position.h"
#include "Bitboard.h"
#include <vector>
#include <set>

/// @brief Color of chessboard pieces
enum class Color
{
    WHITE=1,        ///< White
    BLACK=2,        ///< Black
    NOCOLOR=3,      ///< -
    ANYCOLOR=4,      ///< -
    ALTERNATE=5      ///< -
};

using path = std::vector<Position>;
using trajectory = std::set<path> ;

constexpr int bitVertical1 = 8;
constexpr int bitVertical2 = 2*bitVertical1;
constexpr int bitDiagonalA = 7;
constexpr int bitDiagonalB = 9;
constexpr int bitHorizontal = 1;
constexpr int bitLMoveA = 17;
constexpr int bitLMoveB = 15;
constexpr int bitLMoveC = 10;
constexpr int bitLMoveD = 6;

/// @brief Abstract & base class for chessboard pieces
/// @details Draw allowable trajectory for displacement
/// and give access to some attributes
class Piece {
public:
    // constructors
    Piece(char, Color, int);
    virtual ~Piece() noexcept = default;
    // member methods
    std::string to_String() const;
    virtual Bitboard potentialBitMove(int const &, tuplBitboard const &)const =0;
    //getter/setter
    char getType() const;
    int getValue() const;
    virtual bool isKing() const;
    virtual bool isKingW() const;
    virtual bool isKingB() const;
    virtual bool isRook() const;
    virtual bool isPromoted(Position const &) const;
    Color getColor() const;
    virtual bool isInitialPosition(Position const &) const=0;
protected:
    std::tuple<bool,bool> isIndexValid(int const index, Bitboard bbW, Bitboard bbB) const;
    Bitboard verticalMove(int const & , int const &, tuplBitboard const & ) const;
    Bitboard horizontalMove(int const & , int const &, tuplBitboard const &) const;
    Bitboard diagonalMove(int const & , int const &, tuplBitboard const & ) const;
    Bitboard diagonalMoveA(int const & , int const &, tuplBitboard const & ) const;
    Bitboard diagonalMoveB(int const & , int const &, tuplBitboard const & ) const;
    Bitboard lMove(int const & , tuplBitboard const &) const;
    Bitboard bitMove(int const& , int const &, int const &, tuplBitboard const &, int const &, int const &) const;

    char m_type;
    int m_value;
    Color m_color;
};
std::ostream& operator<<(std::ostream& , Piece &);
std::ostream& operator<<(std::ostream& , Color const &);
