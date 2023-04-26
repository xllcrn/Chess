//
// Created by xllcr on 23/02/2023.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H
#include <string>
#include <vector>
#include "Piece.h"
#include <memory>

class Player {
public:
    Player();
private:
    std::string m_name;
    Color m_color;
    std::vector<std::shared_ptr<Piece>> m_setPieces;
};


#endif //CHESS_PLAYER_H
