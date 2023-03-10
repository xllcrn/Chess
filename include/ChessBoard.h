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
    void printScores();
    bool moveIsValid(Position const &, Position const &) const;
    bool isChess(char const &) const;
    bool isMate(char const &) const;
    bool isChessMate() const;
    void pawnPromotion(Position const &);
    char getPieceType(Position const & pos)const;
    bool isCastling(Position const & pBeforeK, Position const & pAfterK) const;
private:
    // methods
    // ----------
    bool getCastling(ColorOfPieces color)const;
    void setCastling(bool, ColorOfPieces);
    void setKingPosition(Position const &, ColorOfPieces const &);
    void createPiece(char, Position const &, ColorOfPieces);
    void piecesSet(std::string const &);
    void promotion(char const &, Position const & pos);
    Position getKingPosition(char const &)const;
    void checkKing(char const &) const;
    bool chessTest(Position const &, ColorOfPieces) const;
    bool mateTest(Position const &, ColorOfPieces) const;
    void setScore(int const &, ColorOfPieces const &);
    void switch_color(ColorOfPieces);
    trajectory correctTraject(trajectory const &) const;
    trajectory correctTraject(trajectory const &, Position const &) const;
    // attributes
    // ----------
    int m_scoreW;
    int m_scoreB;
    Position m_kingW;
    Position m_kingB;
    ColorOfPieces m_color_active;
    std::map<Position, std::tuple<std::shared_ptr<Piece>, bool>> m_board;
    static int m_lines;
    bool m_castlingW;
    bool m_castlingB;
};
std::ostream& operator<<(std::ostream& , ChessBoard&);
#endif //CHESS_BOARD_H
