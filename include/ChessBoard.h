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
    ChessBoard(std::string const &);
    std::vector<char> chessboardToChar() const;
    std::string boardToString(std::vector<char> const &) const;
    void movePiece(Position const&, Position const&);
    void moveHelp(Position const &);
    int getScoreW() const;
    int getScoreB() const;
    std::shared_ptr<Piece> getPiece(Position const &) ;
    ColorOfPieces getPieceColor(Position const &) ;
    void printScores();
    void setKingPosition(Position const &, ColorOfPieces const &);
    bool moveIsValid(Position const &, Position const &) const;
    bool isChess(char const &) const;
    bool isMate(char const &) const;
    bool isChessMate() const;
private:
    void piecesSet(ColorOfPieces);
    void piecesSet(std::string const &);
    int m_scoreW;
    int m_scoreB;
    Position m_kingW;
    Position m_kingB;
    Position getKingPosition(char const &)const;
    ColorOfPieces m_color_active;
    void checkKing(char const &) const;
    bool chessTest(Position const &, ColorOfPieces) const;
    bool mateTest(Position const &, ColorOfPieces) const;
    void setScore(int const &, ColorOfPieces const &);
    std::map<Position,std::shared_ptr<Piece>> m_board;
    static int m_lines;
    ColorOfPieces switch_color(ColorOfPieces) const;
    trajectory correctTraject(trajectory const &) const;
    trajectory correctTraject(trajectory const &, Position const &) const;
};
std::ostream& operator<<(std::ostream& , ChessBoard&);
#endif //CHESS_BOARD_H
