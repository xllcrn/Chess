
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
#include "Pawn.h"

int main() {

    Position pos1{'c',1},pos2{'h',1};
    Pawn  piece1{ColorOfPieces::WHITE};
    std::cout << piece1;

    ChessBoard board;
    std::cout << board;
    //    std::cout << board;
//    std::map<Position,Piece*> m_board;
//    m_board[pos1] = &piece1;

//    for (auto& elem: m_board){
//        Position pos{elem.first};
//        Piece* p_p{elem.second};
//        std::cout << pos;
//        std::cout << *p_p;
//    }

    Position pos_before{'d',2};
    Position pos_after{'d',3};
    board.movePiece(pos_before,pos_after);
    std::cout << board;
//    board.move(Position{'d',3},Position{'d',4});
//    std::cout << board;
//    std::cout << "on affiche le dernier chessboard \n";
//    ChessBoard board1{board};
//    std::cout << board1;


    Position pos_after2{'d',4};
    board.movePiece(pos_after,pos_after2);
    std::cout << board;

    return 0;
}
