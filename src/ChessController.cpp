#include "ChessController.h"


ChessController::ChessController() {}

ChessController::ChessController(ChessModel const &chessModel, ChessView const & chessView) :
    m_chessModel (chessModel), m_chessView(chessView){}

ChessController::~ChessController() {}

/**
 * Asks to determine who plays first
 * and with which sign (X or O)
 */
void ChessController::initializePlayer() {
    askWhoStarts();
    askPlayersSign();
}

/**
 * Asks user to find who is starting
 * This function will be developed in future.
 * Now computer starts first
 */
void ChessController::askWhoStarts() {
    // TODO ask user about the starting body
    m_chessModel.setStarter(CONFIRM);
}

/**
 * Asks user to find who is starting
 * This function will be developed in future.
 * Now computer starts sign is "X"
 */
void ChessController::askPlayersSign() {
    // TODO  ask user about sign of players
    m_chessModel.setHumanID(Color::WHITE);
    m_chessModel.setComputerID(Color::BLACK);
}

/**
 * Main process of the game
 */
bool ChessController::startGame() {
    Color winner = Color::NOCOLOR;
    std::string winnerName;

    while (winner == Color::NOCOLOR) {
        if (m_chessModel.getNextMove() == HUMAN){
            //Human turn
            askPlayerToMove();
            m_chessModel.changeNextMove();
        } else {
            //askComputerToMove();
            askPlayerToMove();
            m_chessModel.changeNextMove();
        }
        winner = m_chessModel.checkWinner();
    }

    m_chessView.renderGameScreen(m_chessModel.getBoardAsChar(), false);

//    if(winner == TIE){
//        m_chessView.announceNoWinner();
//        return askToPlayAgain();
//    }

    if(winner == m_chessModel.getComputerID())
        m_chessView.announceWinner(m_chessModel.getComputerID(),
                                   m_chessModel.getComputerPlayerName());
    else
        m_chessView.announceWinner(m_chessModel.getHumanID(),
                                 m_chessModel.getHumanPlayerName());

    return askToPlayAgain();
}

/**
 * Asks player about restarting the game
 * @return
 */
bool ChessController::askToPlayAgain(){
    std::string playerAnswer = "";

    m_chessView.prepareAskToPlayAgainQuestion();
    m_chessModel.setStarter((char)toupper(playerAnswer[0]));

    std::cin >> playerAnswer;

    return ((char)toupper(playerAnswer[0]) == CONFIRM);
}

/**
 * Render screen and prepare question and find user answer
 */
void ChessController::askPlayerToMove() {
    int playerStartCellIndex = 0;
    int playerEndCellIndex = 0;
    Move playerMove;
    auto validMove{true};

    do {
        if(!validMove) m_chessView.preparePlayerMoveToRetype();
        m_chessView.renderGameScreen(m_chessModel.getBoardAsChar());
        m_chessView.preparePlayerMoveQuestion();
        playerMove.start_pos = m_chessView.getUserNextMove();
        m_chessView.preparePlayerMoveToQuestion();
        playerMove.end_pos = m_chessView.getUserNextMove();
        validMove = false;
    } while (!m_chessModel.isPlayerMoveValid(playerMove, humanID));

    m_chessModel.recordMove(playerMove, humanID);
}

/**
 * Calls Model to run main logic of computer moves.
 */
void ChessController::askComputerToMove() {
    m_chessModel.doComputerMove();
}
