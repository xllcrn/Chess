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

class ChessBoard final {
public:
    ChessBoard();
    std::vector<char> chessboardToChar() const;
    std::string boardToString(std::vector<char> const &) const;
    void movePiece(Position const&, Position const&);
    void moveHelp(Position const &);
    int getScoreW();
    int getScoreB();
    void printScores();
private:
    void piecesSet(ColorOfPieces);
    int m_scoreW;
    int m_scoreB;
    void setScore(int const &, ColorOfPieces const &);
    std::map<Position,std::shared_ptr<Piece>> m_board;
    static int m_lines;
    trajectory correctTraject(trajectory const &) const;
    trajectory correctTraject(trajectory const &, Position const &) const;
};
std::ostream& operator<<(std::ostream& , ChessBoard&);
#endif //CHESS_BOARD_H
