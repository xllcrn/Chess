//
// Created by xllcr on 21/02/2023.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include <string>
#include <iostream>
#include <sstream>

class Position {
public:
    Position(char const &, int const &);
    std::string to_String() const;
    void setX(char const &);
    void setY(int const &);
    char const & getX() const;
    int const & getY() const;
    int getCoord() const;
private:
    char m_line;
    int m_column;
};
std::ostream& operator<<(std::ostream& , Position const &);
bool operator==(Position const & , Position const &);
bool operator<(const Position& , const Position &);
bool operator!=(Position const & , Position const &);
#endif //PACMAN_POSITION_H