//
// Created by xllcr on 21/02/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "ChessMove.h"
#include <unordered_map>

enum class ChessMateChoice
{
    CHESS=1,       ///< chess
    MATE=2,        ///< mate
    CHESSMATE=3,    ///< chessmate
    NOCHESSMATE=4  ///< no chessmate
};

class ChessBoard final {
public:
    ChessBoard();
    ChessBoard(std::string const &);
    ChessBoard(std::string const &, char);
    std::vector<char> chessboardToChar() const;
    std::string boardToString(std::vector<char> const &) const;
    bool movePiece(Position const&, Position const&, bool =true);
    void moveHelp(Position const &);
    int getScoreW() const;
    int getScoreB() const;
    ColorOfPieces getColorActive()const;
    void printScores();
    bool isChess(char const &) const;
    bool isMate(char const &) const;
    bool isChessMate() const;
    void pawnPromotion(Position const &);
    char getPieceType(Position const & pos)const;
    bool isCastling(Position const & pBeforeK, Position const & pAfterK) const;
    std::tuple<std::vector<ChessMove>,int> potentialMoves(ColorOfPieces);
    bool isChessMate(ChessMateChoice const &, char const &) const;
    bool isMoveValid(Position const &, Position const &) const;
    int compute_score(ColorOfPieces);
    Position getKingPosition(char const &)const;
private:
    // methods
    // ----------
    ColorOfPieces getColorfromChar(char c)const;
    void printActiveColor()const;
    bool getCastling(ColorOfPieces color)const;
    void setCastling(bool, ColorOfPieces);
    void setKingPosition(Position const &, ColorOfPieces const &);
    void createPiece(char, Position const &, ColorOfPieces);
    void piecesSet(std::string const &);
    void promotion(char const &, Position const & pos);
    bool checkKing(char const &) const;
    bool isAttacked(Position const &, std::vector<Position> const &) const;
    bool mateTest(Position const &, ColorOfPieces) const;
    void setScore(int const &, ColorOfPieces const &);
    trajectory drawPotentials(Position const &, bool =false) const;
    std::vector<Position> planAttacked(ColorOfPieces, bool=false) const;
    ChessMateChoice checkChessMate(char const & ) const ;
    // attributes
    // ----------
    int m_scoreW;
    int m_scoreB;
    Position m_kingW;
    Position m_kingB;
    ColorOfPieces m_color_active;
    std::unordered_map<Position, std::tuple<std::shared_ptr<Piece>, bool>> m_board;
    static int m_lines;
    bool m_castlingW;
    bool m_castlingB;
};
std::ostream& operator<<(std::ostream& , ChessBoard&);
std::ostream& operator<<(std::ostream& , ColorOfPieces);
ColorOfPieces switch_color(ColorOfPieces);
ColorOfPieces switch_color(char);
ChessBoard play(ChessMove move, ChessBoard board);
#endif //CHESS_BOARD_H
