
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

int main() {

    Position pos1{'c',1},pos2{'h',1};

    ChessBoard board;
    std::cout << board;

    std::cout << board;
    board.moveHelp({'d',1});

    board.movePiece({'d',1},{'d',4});
    std::cout << board;
//    board.moveHelp({'d',4});
    board.movePiece({'d',4},{'a',7});
    board.movePiece({'a',7},{'a',8});
    std::cout << board;
    std::cout << board.getScoreB();
    std::cout << board.getScoreW();
    //Position pos({'e',13});
    board.movePiece({'c',1},{'e',3});
    std::cout << board;
    board.moveHelp({'e',1});
    board.moveHelp({'e',7});
    return 0;
}
