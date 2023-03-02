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
    Position(char const &, unsigned int const &);
    std::string to_String() const;
    void setX(char const &);
    void setY(unsigned int const &);
    char const & getX() const;
    unsigned int const & getY() const;
    int getCoord() const;
private:
    char m_line;
    unsigned int m_column;
    static const char& validate_line(const char& line);
    static const unsigned int& validate_column(const unsigned int& column);
};
std::ostream& operator<<(std::ostream& , Position const &);
bool operator==(Position const & , Position const &);
bool operator<(const Position& , const Position &);
bool operator!=(Position const & , Position const &);
#endif //PACMAN_POSITION_H