//
// Created by xllcr on 21/02/2023.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include <string>
#include <iostream>
#include <sstream>

typedef enum ListeDesDirections
{
    positionCourante,
    haut,
    bas,
    gauche,
    droite,
    max_dir
}
        Direction;

class Position {
public:
    Position();
    Position(char const &, int const &);
    Position(Position const &);
    ~Position();
    Position & operator=(Position const &);
    std::string to_String();
    void setX(char const &);
    void setY(int const &);
    void setCoord(int const &);
    char const & getX() const;
    int const & getY() const;
    int const & getCoord() const;
private:
    char m_line;
    int m_column;
    int m_coord;
};
std::ostream& operator<<(std::ostream& , Position &);
bool operator==(Position& , Position &);
bool operator<(const Position& , const Position &);
bool operator!=(Position& , Position &);
Position new_position(Position const &, Direction const &);
#endif //PACMAN_POSITION_H