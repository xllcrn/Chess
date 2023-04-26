#pragma once
#include "ChessModel.h"
#include "ChessView.h"


/**
 * Controller Class
 */
class ChessController {
public:
    ChessController();
    ChessController(ChessModel const & chessModel, ChessView const & chessView);
    virtual ~ChessController();

    void initializePlayer();
    bool startGame();

private:
    Color humanID = Color::WHITE;
    Color computerID = Color::BLACK;
    bool nextMoveIsByHuman = true ;

    ChessModel m_chessModel;
    ChessView m_chessView;

    void askWhoStarts();
    void askPlayerToMove();

//    void calculateAndDoYourMove();
//    int getUserNextMove();

    void askComputerToMove();
    void askPlayersSign();
    bool askToPlayAgain();

};