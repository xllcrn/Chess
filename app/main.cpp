
/********************************************************************/
/* Projet Chess                                                     */
/*------------------------------------------------------------------*/
/* Module            : Chess                                        */
/* Numéro de version : 0.1                                          */
/* Date              : 21/02/2023                                   */
/* Auteurs           : Axelle CARON                                 */
/********************************************************************/


#include <iostream>
#include "ChessBoard.h"
#include <stdexcept>
int main() {

    Position pos1= Position::create_position('c',1);
    Position pos2= Position::create_position('h',1);

    ChessBoard board;
    std::cout << board;
//
//    std::cout << board;
//    board.moveHelp({'d',1});
//
//    board.movePiece({'d',1},{'d',4});
//    std::cout << board;
////    board.moveHelp({'d',4});
//    board.movePiece({'d',4},{'a',7});
//    board.movePiece({'a',7},{'a',8});
//    std::cout << board;
//    std::cout << board.getScoreB();
//    std::cout << board.getScoreW();
//    //Position pos({'e',13});
//    board.movePiece({'c',4},{'c',5});
//    std::cout << board;
//    board.moveHelp({'e',1});
//    board.moveHelp({'e',7});
//
//    board.printScores();
//    board.movePiece({'e',7},{'e',6});
    board.movePiece(Position::create_position('e',2),Position::create_position('e',4));
    std::cout << board;

    board.movePiece(Position::create_position('e',7),Position::create_position('e',5));
    std::cout << board;

    board.moveHelp(Position::create_position('d',1));


    return 0;
}