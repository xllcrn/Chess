//
// Created by xllcr on 21/02/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <iostream>
#include "Position.h"
#include "Piece.h"
#include <map>

class ChessBoard {
public:
    ChessBoard();
    //ChessBoard(ChessBoard const &);
    ~ChessBoard();
    std::string toString();
    void movePiece(Position&, Position&);
//    void move(Position&&, Position&&);
private:
    int position2coordinate(Position&);
    void piecesSet(ColorOfPieces);
    std::map<Position,std::shared_ptr<Piece>> m_board;
    static int m_lines;
//    Player m_playerW, m_playerB;
};
std::ostream& operator<<(std::ostream& , ChessBoard&);

#endif //CHESS_BOARD_H
