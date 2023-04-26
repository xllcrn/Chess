#include <string>

#include "ChessModel.h"

ChessModel::ChessModel() :m_board (std::make_unique<Board>("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")){}

ChessModel::ChessModel(std::string const & boardStr): m_board(std::make_unique<Board>(boardStr)){
}

ChessModel::~ChessModel() {}

ChessModel::ChessModel(ChessModel const & chessmodel){
    std::string vecStr = chessmodel.m_board->boardToString();
    m_board=std::make_unique<Board>(Board(vecStr));
}

std::vector<char> ChessModel::getBoardAsChar() const{
    return m_board->boardToChar();
}

tuplBitboard ChessModel::getBoardAsBit() const{
    return m_board->boardToBit();
}


/**
 * Checks the player movement to be valid
 * @param cellIndex
 * @return bool result of check process
 */
bool ChessModel::isPlayerMoveValid(Move moveIndex, Color playerID) {
    return isMoveValid(moveIndex,playerID);
}

/**
 * Checks to find a cell is empty or not
 * @param CellIndex
 * @return bool result of check process
 */
//bool ChessModel::isCellEmpty(int CellIndex) {
//    if (boardLayout[CellIndex] == ' ')
//        return true;
//    else
//        return false;
//}

/**
 * Check to fine whether cell Index is in valid range
 * @param cellIndex
 * @return bool result of check process
 */
bool ChessModel::isMoveValid(Move moveIndex, Color playerID) {
    int start_pos{moveIndex.start_pos};
    int end_pos{moveIndex.end_pos};

    if (start_pos < STARTCELLINDEX || start_pos > ENDCELLINDEX ||
        end_pos   < STARTCELLINDEX || end_pos   > ENDCELLINDEX ||
        start_pos==end_pos){
        return false;}
    else{
        // is right color to play? and also check existence of a piece at the start index
        const auto&[bbW,bbB] = getBoardAsBit();
        if ((playerID==Color::WHITE && (getBit(bbW,start_pos)==0)) ||
            (playerID==Color::BLACK && (getBit(bbB,start_pos)==0)) )
            return false;

        Bitboard bbPotential = findPotentials(start_pos);
        // if end index is among potentials : check if my king threatened AFTER the move
        if(getBit(bbPotential,end_pos) == 1)
            return (isMoveValidForKing(moveIndex,playerID));
        else
            return false;
    }
}

Bitboard ChessModel::findPotentials(Bitboard bb) const {
    Bitboard bbPotential{0};
    tuplBitboard bb2 = getBoardAsBit();
    for (auto j=0; j<8*sizeof(Bitboard); j++){
        if (getBit(bb,j)==1)
            bbPotential = (bbPotential | m_board->getPiece(j)->potentialBitMove(j,bb2));
    }
    return bbPotential;
}

Bitboard ChessModel::findPotentials(int index) const {
    if(m_board->isPiece(index))
        return m_board->getPiece(index)->potentialBitMove(index, getBoardAsBit());
    else
        return 0ULL;
}


/**
 * Check if index is threatened
 * @param cellIndex
 * @return bool result of check process
 */
bool ChessModel::isMoveValidForKing(Move const & moveIndex, Color const playerID) {
    if(moveIndex.start_pos==moveIndex.end_pos)
        return false;
    else {
        const auto&[bbW, bbB] = getBoardAsBit();
        recordMove(moveIndex, playerID);
        bool kingTheatened = isKingThreatened(playerID);
        cancelLastMove();
//    auto[bbW2,bbB2] = getBoardAsBit();
//    assert(bbW==bbW2 && bbB==bbB2 && "Check on cancel move");
        return !kingTheatened;
    }
}


bool ChessModel::isKingThreatened(Color const playerID) const {
    const auto&[bbW,bbB] = getBoardAsBit();
    Bitboard bbOtherColor{0};
    int indexKing;
    if (playerID==Color::WHITE) { //king white, bbOtherColor black
        indexKing = m_board->getkingPosition('k');
        bbOtherColor = bbB;
    }
    else { //king black, bbOtherColor white
        indexKing = m_board->getkingPosition('K');
        bbOtherColor = bbW;
    }
    if (indexKing==-1) return false;
    Bitboard bbThreats{findPotentials(bbOtherColor)};

    // Chess : threaten on its position
    return getBit(bbThreats,indexKing)==1;
}




/**
 * Check if king of color playerID is chessmate
 * @param cellIndex
 * @return bool result of check process
 */
bool ChessModel::isChessMate(Color const playerID, KingThreat const threatType) {
    bool chess= false;
    bool mate = false;
    const auto&[bbW,bbB] = getBoardAsBit();
    Bitboard bbOtherColor{0};
    int indexKing;
    if (playerID==Color::WHITE) { //king white, bbOtherColor black
        indexKing = m_board->getkingPosition('k');
        bbOtherColor = bbB;
    }
    else { //king black, bbOtherColor white
        indexKing = m_board->getkingPosition('K');
        bbOtherColor = bbW;
    }
    if (indexKing==-1) return false;
//    Bitboard bbThreats{findPotentials(bbOtherColor)};
    Bitboard bbKingPotentials{findPotentials(indexKing)};
    if(bbKingPotentials!=0ULL) {
        bool notMate = false;
        for (auto bit = 0; bit < 8 * sizeof(Bitboard); bit++) {
            if (getBit(bbKingPotentials, bit) == 1) {
                if (isMoveValidForKing({indexKing, bit}, playerID)) {
                    notMate = true;
                    break;
                }
            }
        }
        mate  = !notMate;
    } else
        mate = true;

    chess = isKingThreatened(playerID);

    if (threatType==KingThreat::CHESS)
        return chess;
    else if (threatType==KingThreat::MATE)
        return mate;
    else if (threatType==KingThreat::CHESSMATE)
        return chess && mate;
}

/**
 * Check to find whether there is a winner or not
 * @return player ID of winner(X or O) or "T" when games come to a tie
 */
Color ChessModel::checkWinner() {
    if(isChessMate(Color::WHITE, KingThreat::CHESSMATE))
        return Color::BLACK;
    else if(isChessMate(Color::BLACK, KingThreat::CHESSMATE))
        return Color::WHITE;
    return Color::NOCOLOR;
}

/**
 * Sets boardLayout and moveSequence based of most recent move of a playes
 * @param cellIndex int cell index of most recent move
 * @param playerID char player ID (X or O)
 */
void ChessModel::recordMove(Move moveIndex, Color playerID) {
    std::shared_ptr<Piece> p_piece = m_board->getPiece(moveIndex.start_pos);
    bool pieceDeleted = m_board->movePieceForward(moveIndex);
    moveSequence.emplace_back(std::make_tuple(p_piece,moveIndex,playerID,pieceDeleted));
}

/**
 * Sets boardLayout and moveSequence based of most recent move of a playes
 * @param cellIndex int cell index of most recent move
 * @param playerID char player ID (X or O)
 */
void ChessModel::cancelLastMove() {
    if (!moveSequence.empty()) {
        auto&[p_piece, move, player, isPieceDeleted] = moveSequence.back();
        m_board->movePieceBackward(move,isPieceDeleted);
        moveSequence.pop_back();
    }
}

/**
 * Sets starter based on user answer
 * @param userStarter
 */
void ChessModel::setStarter(char userStarter) {
    if (userStarter == CONFIRM) {
        nextMove = COMPUTER;
        startingPlayer = COMPUTER;
    } else {
        nextMove = HUMAN;
        startingPlayer = HUMAN;
    }
}

/**
 * Determines who should do next move
 * @return bool (for "computer" true and for "human" false)
 */
bool ChessModel::getNextMove() {
    return nextMove;
}

/**
 * Change player turn
 */
void ChessModel::changeNextMove() {
    if (nextMove == COMPUTER) {
        nextMove = HUMAN;
    } else {
        nextMove = COMPUTER;
    }
}

void ChessModel::setHumanID(Color playerID) {
    humanID = playerID;
}

void ChessModel::setComputerID(Color playerID) {
    computerID = playerID;
}

Color ChessModel::getHumanID() {
    return humanID;
}

Color ChessModel::getComputerID() {
    return computerID;
}

std::string ChessModel::getComputerPlayerName() {
    return COMPUTERPLAYERNAME;
}

std::string ChessModel::getHumanPlayerName() {
    return HUMANPLAYERNAME;
}


//
///**
// * Main logic of computer movement
// */
void ChessModel::doComputerMove() {
//
//    int playerCellIndex;
//
//    srand((unsigned) time(0));
//
//    // Try to win
//    playerCellIndex = findWinnerCellIndex(computerID);
//    if (playerCellIndex != NOTVALIDINDEX) {
//        recordMove(playerCellIndex, computerID);
//        return;
//    }
//
//    // Prevent other party not to win
//    playerCellIndex = findWinnerCellIndex(humanID);
//    if (playerCellIndex != NOTVALIDINDEX) {
//        recordMove(playerCellIndex, computerID);
//        return;
//    }
//
//    if (startingPlayer == COMPUTER) {
//        switch (lastMoveIndex) {
//            case NOTSTARTED:
//                // select a corner by random
//                playerCellIndex = findRandomCorner();
//                recordMove(playerCellIndex, computerID);
//                return;
//
//            case 1:
//                // find human player first move type
//
//                if (isCorner(moveSequence[lastMoveIndex])) {
//                    playerCellIndex = findRandomCorner();
//                    recordMove(playerCellIndex, computerID);
//                    return;
//                }
//
//                // Check if human first move is at the center
//                if (moveSequence[lastMoveIndex] == CENTER) {
//                    playerCellIndex = findOppositeCorner(moveSequence[lastMoveIndex - 1]);
//                    recordMove(playerCellIndex, computerID);
//                    return;
//                }
//
//                if (isNearEdge(moveSequence[0], moveSequence[lastMoveIndex])) {
//                    humanUsedNearEdge = true;
//                    recordMove(CENTER, computerID);
//                    return;
//                }
//
//                // So it is a far edge
//                recordMove(CENTER, computerID);
//
//                break;
//
//            case 3:
//                int nextMoveIndex = getNextCornerIndex();
//                if (nextMoveIndex != NOTVALIDINDEX) {
//                    recordMove(nextMoveIndex, computerID);
//                } else {
//                    int f = findAFreeCornerIndex();
//                    recordMove(findAFreeCornerIndex(), computerID);
//                }
//
//                break;
//
//        }
//    } else {
//        // Code for the time that player started first should be placed here
//    }
}
//
///**
// * Check if there is a n empty cell that can cause win.
// * @param playerID (X or O)
// * @return int index of winner cell (which is empty now)
// */
//int ChessModel::findWinnerCellIndex(Color playerID) {
//
//    int winnerCellIndex;
//
//    //check Horizontal cells
//    for (int i = 0; i < MAXCELLCOUNT; i += SIDECELLCOUNT) {
//        winnerCellIndex = findWinnerCell(i, 1, playerID);
//        if (winnerCellIndex != NOTVALIDINDEX) {
//            return winnderCellIndex;
//        }
//    }
//
//    //check Horizontal cells
//    for (int i = 0; i < SIDECELLCOUNT; i++) {
//        winnerCellIndex = findWinnerCell(i, 3, playerID);
//        if (winnerCellIndex != NOTVALIDINDEX) {
//            return winnerCellIndex;
//        }
//    }
//
//    //check diagonal cells
//    winnerCellIndex = findWinnerCell(0, 4, playerID);
//    if (winnerCellIndex != NOTVALIDINDEX) {
//        return winnerCellIndex;
//    }
//    winnerCellIndex = findWinnerCell(2, 2, playerID);
//    if (winnerCellIndex != NOTVALIDINDEX) {
//        return winnerCellIndex;
//    }
//
//    return NOTVALIDINDEX;
//}
//
///**
// * Finds an empty cell which can be used to win in a three cells set
// *   (vertical or horizontal or diagonal)
// * @param start Starting cell index
// * @param increment is increment in cell index to find next cell index
// *         (1 for row and 3 for column and ...)
// * @param playerID
// * @return emptyCellIndex or NOTVALIDINDEX
// */
//int ChessModel::findWinnerCell(int start, int increment, char playerID) {
//
//    int similarCellCount = 0;
//    int emptyCellCount = 0;
//    int emptyCellIndex = NOTVALIDINDEX;
//    int index = start;
//
//    for (int j = 0; j < SIDECELLCOUNT; j++) {
//        if (boardLayout[index] == NODATACHAR) {
//            emptyCellCount++;
//            emptyCellIndex = index;
//        } else {
//            if (boardLayout[index] == playerID)
//                similarCellCount++;
//        }
//
//        index += increment;
//    }
//
//    if (similarCellCount == 2 && emptyCellCount == 1)
//        return emptyCellIndex;
//    else
//        return NOTVALIDINDEX;
//}
//
//void ChessModel::setNextCornerIndex(int nextCornerIndex) {
//    this->nextCornerIndex = nextCornerIndex;
//}
//
//int ChessModel::getNextCornerIndex(void) {
//    return nextCornerIndex;
//}
//
///**
// * Creates a list of free cell numbers
// * @return string
// */
////std::string ChessModel::getFreeBoardCellsNumbers() {
////
////    std::string freeBoardCellsNumbers = "(";
////    bool first = true;
////
////    for (int i = 0; i < MAXCELLCOUNT; i++) {
////        if (boardLayout[i] == ' '){
////            if(first != true){
////                freeBoardCellsNumbers += ", ";
////            }
////            else{
////                first = false;
////            }
////            freeBoardCellsNumbers += to_string(i + 1);
////        }
////    }
////
////    freeBoardCellsNumbers += ")";
////
////    return freeBoardCellsNumbers;
////}
//
//bool ChessModel::isCorner(int cellIndex) {
//    if (cellIndex != CENTER && cellIndex % 2 == 0)
//        return true;
//    else
//        return false;
//}
//
///**
// * Finds an empty corner place
// * @return int index of founded cell if there is any, otherwise returns NOTVALIDINDEX
// */
//int ChessModel::findAFreeCornerIndex(void) {
//    for (int i = 0; i < CORNERCOUNT; i++) {
//        if (isCellEmpty(cornerList[i]))
//            return cornerList[i];
//    }
//    return NOTVALIDINDEX;
//}
//
///**
// * Finds whether the last used place is an edge and is neighbor of previous one
// * @param cornerCellIndex
// * @param unknownIndex
// * @return
// */
//bool ChessModel::isNearEdge(int cornerCellIndex, int recentMoveIndex) {
//    for (int i = 0; i < CORNERCOUNT * 2; i++) {
//        if (neighbors[i].usedCornerindex == cornerCellIndex) {
//            if (recentMoveIndex == neighbors[i].nearEdgeIndex) {
//                setNextCornerIndex(neighbors[i].cornerIndexForNextUse);
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
///**
// * Finds a random corner cell which has not been used
// * @return int playerCellIndex which is index of a corner cell
// */
//int ChessModel::findRandomCorner() {
//    int playerCellIndex;
//    do {
//        playerCellIndex = (rand() % 4) * 2;
//        if (playerCellIndex >= CENTER)
//            playerCellIndex += 2;
//    } while (!isCellEmpty(playerCellIndex));
//
//    return playerCellIndex;
//}
//
///**
// * returns opposite corner cell index
// * @param cellIndex is index of a corner cell
// * @return opposite corner cell index
// */
//int ChessModel::findOppositeCorner(int cellIndex) {
//
//    return ENDCELLINDEX - cellIndex;
//}
//

//

//
//
//ChessMateChoice ChessModel::checkChessMate(char const & king) const {
//    // checks on king
//    if (!checkKing(king)) { return ChessMateChoice::NOCHESSMATE;}
//
//    // get king position
//    Position kingPos{getKingPosition(king)};
//
//    // chess test
//    trajectory traject = drawPotentials(kingPos);
//    if(traject.empty()) {
//        return ChessMateChoice::CHESSMATE;
//    }
//    else{ // find its po*sition in the traject
//        bool kingFound = false;
//        unsigned int trajectSize=0;
//        for (path const &path1 : traject) {
//            trajectSize +=path1.size();
//            if (std::find(path1.begin(), path1.end(), kingPos) != path1.end()) {
//                kingFound = true;
//            }
//        }
//        for (path const &path1 : traject) {
//            for (Position const &pos : path1) {
//                if (pos == kingPos){kingFound = true;}
//            }
//        }
//        if (!kingFound) {
//            return ChessMateChoice::CHESS;}
//        else {
//            if (trajectSize==1) return ChessMateChoice::MATE;
//        }
//    }
//    return ChessMateChoice::NOCHESSMATE;
//}
//
/**
 * Prepares a copy of the board layout array
 * @param char * boardLayoutCopy is a copy of boardStatus from Model
 * @return char * a copy of boardStatus from Model
 */
//char * ChessModel::getBoardStatusCopy(char * boardLayoutCopy) {
//    for (int i = 0; i < MAXCELLCOUNT; i++)
//        boardLayoutCopy[i] = boardLayout[i];
//
//    return boardLayoutCopy;
//}
