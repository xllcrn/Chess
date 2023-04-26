#pragma once

#define NODATACHAR ' '

#define TIE 'T'

#include <string>
#include "Piece.h"
#include "ChessMove.h"
#include "Bitboard.h"
#include "Board.h"

/// @brief Color of chessboard pieces
enum class KingThreat
{
    CHESS=1,        ///<
    MATE=2,        ///<
    CHESSMATE=3      ///< -
};


//using namespace std::string_view_literals;
inline std::string COMPUTERPLAYERNAME="Computer";
inline std::string HUMANPLAYERNAME="Human player";

constexpr int MAXCELLCOUNT= 64;
constexpr int NOTSTARTED=-1;
constexpr bool COMPUTER=true;
constexpr bool HUMAN=false;
constexpr char CONFIRM='Y';
constexpr int STARTCELLINDEX= 0;
constexpr int ENDCELLINDEX =MAXCELLCOUNT - 1;
constexpr int NOTVALIDINDEX= -1;


/**
 * Model Class
 */
class ChessModel {
public:
    ChessModel();
    ChessModel(std::string const &);
    ChessModel(ChessModel const &);

    virtual ~ChessModel();

    std::vector<char> getBoardAsChar() const;
    tuplBitboard getBoardAsBit() const;
    bool isPlayerMoveValid(Move cellNumberMove, Color playerID);

    Bitboard findPotentials(int index) const;
    Bitboard findPotentials(Bitboard bb) const;
    bool isKingThreatened(Color const) const;
    bool isMoveValidForKing(Move const & moveIndex, Color const playerID);
    void recordMove(Move moveIndex, Color playerID);
    void cancelLastMove();
    bool isChessMate(Color const playerID, KingThreat const threatType);

    void setStarter(char userStarter);
    bool getNextMove();
    void changeNextMove();

    void doComputerMove();
    void setHumanID(Color playerID);
    void setComputerID(Color playerID);

    Color getHumanID();
    Color getComputerID();

    std::string getComputerPlayerName();
    std::string getHumanPlayerName();

    // to put in private when validated
    bool isMoveValid(Move move, Color playerID);
//    char getBoardStatus(int index);
    Color checkWinner();
//    void startGame();
//    std::string getFreeBoardCellsNumbers();
//    char * getBoardStatusCopy(char * boardLayoutCopy);
private:
    std::vector<std::tuple<std::shared_ptr<Piece>,Move,Color,bool>> moveSequence; /// moveSequence is list of players movements
    int lastMoveIndex = NOTSTARTED;
    int nextCornerIndex = NOTVALIDINDEX;

    bool nextMove;
    bool startingPlayer;
    bool humanUsedNearEdge;

    Color humanID;
    Color computerID;

    std::unique_ptr<Board> m_board;


//    bool isCellEmpty(int cellNumber);
//
//    bool isCorner(int cellNumber);
//    bool isNearEdge(int cornerCellIndex, int unknownIndex);
//
//    int findRandomCorner();
//    int findOppositeCorner(int cellIndex);
//
//    int findWinnerCellIndex(char playerID);
//    int findWinnerCell(int start, int increment, char playerID);
//
//    void setNextCornerIndex(int nextCornerIndex);
//    int getNextCornerIndex(void);
//
//    int findAFreeCornerIndex(void);
};

