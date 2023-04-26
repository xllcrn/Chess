#pragma once

#include <iostream>

#include "ViewListener.h"
#include "Piece.h"
#include "Board.h"

constexpr int ROWCOUNT=8;
constexpr int  COLUMNCOUNT=8;

/**
 * View class
 */
class ChessView {
public:
    ChessView();
    virtual ~ChessView();

    void renderGameScreen(std::vector<char> boardStatus, bool drawHint = true);
    void prepareStartingBodyQuestion();
    void preparePlayerMoveQuestion();
    void preparePlayerMoveToQuestion();
    void prepareAskToPlayAgainQuestion();
    void preparePlayerMoveToRetype();
    void announceWinner(Color winnerID, std::string winnerName);
    void announceNoWinner();

    int getUserNextMove();
    friend std::ostream& operator <<(std::ostream& os, Board board);
    void drawBoard(std::vector<char> boardDataArray);
private:
    void showBoardMap(std::vector<char> boardStatus);
    void drawBoardStaticLine(int)const;
    void drawBoardLine(std::vector<char> boardStatus, int lastRowNum);
    void drawBoardCellRow(std::vector<char> dataArray, int lastRowNum);
    void showGameBoard(std::vector<char> boardStatus);
    void drawGameBoardHint(std::vector<char> boardStatus);
};

