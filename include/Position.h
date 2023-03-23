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
    std::string to_String() const;
    void setX(char const &);
    void setY(unsigned int const &);
    char const & getX() const;
    unsigned int const & getY() const;
    int getCoord() const;
    static Position create_position(char const &, unsigned int const &);
    static Position create_init_position();
private:
    char m_line;
    unsigned int m_column;
    Position(char const &, unsigned int const &);
};
std::ostream& operator<<(std::ostream& , Position const &);
bool operator==(Position const & , Position const &);
bool operator<(const Position& , const Position &);
bool operator!=(Position const & , Position const &);
namespace std{
    template<>
    struct hash<Position>
    {
        typedef Position argument_type;
        typedef size_t result_type;
        result_type operator() (argument_type const & pos) const{
            result_type hashValue = 17;
            hashValue = 31*hashValue + std::hash<int>{}(pos.getY());
            hashValue = 31*hashValue + std::hash<char>{}(pos.getX());
            return hashValue;
        }
    };
}
#endif //PACMAN_POSITION_H