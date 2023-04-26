#include <Position.h>
#include "ChessView.h"

ChessView::ChessView() {}

ChessView::~ChessView() {}

/**
 * Draws a line of board
 * @param boardStatus
 * @param lastRowNum
 */
void ChessView::drawBoardLine(std::vector<char> boardStatus, int lastRowNum) {
    if (((lastRowNum ) % ROWCOUNT) == 0) return;

    std::string noDataLine = "";
    noDataLine += "---";
    noDataLine +="|";
    for (int j = 0; j < COLUMNCOUNT; j++) {
        noDataLine += "---";
        if (((j + 1) % COLUMNCOUNT) != 0)
            noDataLine += "|";
    }
    noDataLine +="|";
    noDataLine += "---";
    std::cout << noDataLine << "\n";
}

void ChessView::drawBoardStaticLine(int i)const {
    std::string HyphenDataLine = "   ---------------------------------   ";
    std::string DataLine = "   | a | b | c | d | e | f | g | h |";
    if (i==1) std::cout << HyphenDataLine << "\n";
    std::cout << DataLine << "\n";
    if (i==0) std::cout << HyphenDataLine << "\n";
}


/**
 *
 * @param dataArray
 * @param lastRowNum
 */
void ChessView::drawBoardCellRow(std::vector<char> dataArray, int lastRowNum) {

    std::string boardRow = "";
    std::string s,s0;
    s0 = std::to_string(lastRowNum+1);
    boardRow += " " + s0 + " |";
    for (int j = 0; j < COLUMNCOUNT; j++) {
        s = dataArray[lastRowNum * 8 + j];
        boardRow += " " + s + " ";
        if (((j + 1) % COLUMNCOUNT) != 0)
            boardRow += "|";
    }
    boardRow += "| " + s0 + " " ;
    std::cout << boardRow << "\n";
}

void ChessView::drawBoard(std::vector<char> boardDataArray) {
    drawBoardStaticLine(0);
    for (int i = ROWCOUNT-1; i >= 0; i--) {
        drawBoardCellRow(boardDataArray, i);
        drawBoardLine(boardDataArray, i);
    }
    drawBoardStaticLine(1);
}

/**
 *
 * @param boardStatus
 */
void ChessView::showGameBoard(std::vector<char> boardStatus) {
    std::cout << "=================\n";
    std::cout << " Computer: Black \n";
    std::cout << "  Player: White  \n";
    std::cout << "=================\n";
    std::cout << " Game Board      \n";
    std::cout << "=================\n";
    drawBoard(boardStatus);
    std::cout << "\n\n";
}

//void ChessView::drawGameBoardHint(char * boardStatus) {
//    char boardHintData[9];
//    int dataArraySize = ROWCOUNT * COLUMNCOUNT;
//
//    std::cout << "\n\n";
//    std::cout << "===============\n";
//    std::cout << "Game Board Map \n";
//    std::cout << "===============\n";
//
//    for (int i = 0; i < dataArraySize; i++) {
//        if (boardStatus[i] == ' ')
//            boardHintData[i] = to_string(i + 1)[0];
//        else
//            boardHintData[i] = ' ';
//    }
//
//    drawBoard(boardHintData);
//    std::cout << "\n\n";
//}

/**
 * Shows game on screen
 * @param char * boardStatus a copy of boardStatus from Model
 * @param bool drawHint true means hint should be drawn
 */
void ChessView::renderGameScreen(std::vector<char> boardStatus, bool drawHint) {
    system("cls"); /** System call */
    showGameBoard(boardStatus);
//    if (drawHint)
//        drawGameBoardHint(boardStatus);

}

void ChessView::preparePlayerMoveQuestion() {
    std::cout << "Select a cell number (ex: a1) for your piece to move -> ";
}

void ChessView::preparePlayerMoveToQuestion() {
    std::cout << "Select a cell number (ex: b2) as a destination for your next move -> ";
}

void ChessView::preparePlayerMoveToRetype() {
    std::cout << "Move is not valid, please try again \n";
}

void ChessView::prepareAskToPlayAgainQuestion() {
    std::cout << "Do you want to play again? (Y or N) ";
}


bool ReadChar(char& s, int& v) {
    if (!(std::cin >> s >> v) || s < 'a' || s > 'h' || v < 1 || v > 8) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool ReadInt(int& v) {
//    do {
//        std::cout << prompt << ": ";
//        if (std::cin >> value) break;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "Invalid input. Enter a valid number" << std::endl;
//    }
//    while (true);

    if (!(std::cin >> v)|| !isdigit(v) || v < 1 || v > 8) return false;
    return true;
}



/**
 * Gets user next move by asking cell number
 * @return int selected CellIndex, which is equal to playerNextCellNumber - 1
 */
int ChessView::getUserNextMove(){
    char playerAlpha;
    int playerDigit;
    bool isValidEntry;
    do{
        isValidEntry = ReadChar(playerAlpha, playerDigit);
        if (!isValidEntry) {
            std::cout << "Incorrect entry ! Type position again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(!isValidEntry);
    auto playerNextCellNumber = Position::create(playerAlpha,playerDigit);
    return playerNextCellNumber.getIndex();
}

void ChessView::announceWinner(Color winnerID, std::string winnerName) {
    std::cout << "\n*******************************\n";
    std::string colorStr = "white";
    if (winnerID == Color::BLACK) colorStr = "black";
    std::cout << "*** " << winnerName << " (" << colorStr << ") is winner! ***\n";
    std::cout << "*******************************\n\n";
}

void ChessView::announceNoWinner() {
    std::cout << "\n ------------------------\n";
    std::cout << " Tie! No one is winner!\n";
    std::cout << " ------------------------\n";
}

//std::ostream& operator <<(std::ostream& os, Board board)
//{
//    os << drawBoard(board.boardToChar());
//    return os;
//}
