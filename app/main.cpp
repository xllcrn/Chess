
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
    Position pos2= Position::create_position('b',8);

    ChessBoard board("000rh0kP/rp00p0pq/0P0P0P0P/8/8/8/8/RQH0K0R0");
//    ChessBoard board;
    std::cout << board;
    Position posBefore= Position::create_position('a',2);
    Position posAfter= Position::create_position('a',3);
    board.movePiece(posBefore,posAfter);
    std::cout << board;
    board.movePiece(posBefore,Position::create_position('c',4));
    std::cout << board;

    ChessBoard board2("8/8/00q00000/8/8/8/8/8");
    Position queen_pos= Position::create_position('c',3);
    std::cout << board2;
    Position queen_pos_diag= Position::create_position('g',7);


    ChessBoard board3("8/8/8/000pq000/8/8/00P00000/8");
    Position king_pos = Position::create_position('e', 4);
    Position pawn_pos = Position::create_position('d', 4);
    Position pawn_pos_vert1 = Position::create_position('d', 5);
    Position pawn_pos_vert2 = Position::create_position('d', 6);
    Position king_pos_hori1 = Position::create_position('d', 4);
    Position pawn_pos_diag1 = Position::create_position('c', 5);
    std::cout << board3.moveIsValid(king_pos,king_pos_hori1);
    std::cout << board3.moveIsValid(pawn_pos,pawn_pos_vert1);
    std::cout << board3.moveIsValid(pawn_pos,pawn_pos_vert2);
    std::cout << board3.moveIsValid(pawn_pos,pawn_pos_diag1);


//    board.movePiece(Position::create_position('e',2),Position::create_position('d',3));
//    std::cout << board;
//
//
//    char c=board.getPiece(pos2)->getType();
//    std::cout << c;
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


//    board.movePiece(Position::create_position('e',2),Position::create_position('e',4));
//    std::cout << board;
//
//    board.movePiece(Position::create_position('e',7),Position::create_position('e',5));
//    std::cout << board;
//
//    board.moveHelp(Position::create_position('d',1));


    return 0;
}
