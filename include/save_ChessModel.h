//
// Created by xllcr on 21/02/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <AbstractChessModel.h>
#include <vector>
#include "BoardFactory.h"

class ChessModel final : public AbstractChessModel{
public:
    ChessModel():AbstractChessModel(){}
    ChessModel(std::string const & str):AbstractChessModel(str){}
    bool movePiece(Position const&, Position const&, bool =true);
    void moveHelp(Position const &);
    int getScoreW() const;
    int getScoreB() const;
    Color getColorActive()const;
    void printScores();
//    void pawnPromotion(Position const &);
//    char getPieceType(Position const & pos)const;
//    bool isCastling(Position const & pBeforeK, Position const & pAfterK) const;
//    std::tuple<std::vector<ChessMove>,int> potentialMoves(Color) override;
//    bool isChessMate(ChessMateChoice const &, char const &) const override;
//    bool isMoveValid(Position const &, Position const &) const;
//    int compute_score(Color);
    std::vector<char> chessBoardToChar() const;
private:
    // methods
    // ----------
    Color getColorfromChar(char c)const;
    void printActiveColor()const;
    bool getCastling(Color color)const;
    void setCastling(bool, Color);
//    void promotion(char const &, Position const & pos);
    bool checkKing(char const &) const;
    bool isAttacked(Position const &, std::vector<Position> const &) const;
    void setScore(int const &, Color const &);
    trajectory drawPotentials(Position const &, bool =false) const;
    std::vector<Position> planAttacked(Color, bool=false) const;
    ChessMateChoice checkChessMate(char const & ) const ;
    // attributes
    // ----------
    int m_scoreW= 0;
    int m_scoreB= 0;
    Color m_color_active= Color::WHITE;
    static int m_lines;
    bool m_castlingW = false;
    bool m_castlingB = false;
};
Color switch_color(Color);
Color switch_color(char);
//ChessBoard play(ChessMove move, ChessBoard board);
#endif //CHESS_BOARD_H
