
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



    ChessBoard short_board2("r000kbhr/pbppqppp/00h00000/0000p000/00B0P000/00HP0H00/PPP00PPP/R0BQK00R");
    Position king_pos  = Position::create_position('e', 1);

    Position king_posl  = Position::create_position('c', 1);
    Position rook_posl  = Position::create_position('d', 1);
    short_board2.movePiece(king_pos,king_posl);

    std::cout << short_board2;

//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos)<< std::endl;
//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert1)<< std::endl;
//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert2)<< std::endl; //ici
//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert3)<< std::endl;
//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_diag1)<< std::endl;
//    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_diag2)<< std::endl;
//
//    Position pawn_pos0= Position::create_position('a', 2);
//    Position pawn_pos_vert11  = Position::create_position('a', 3);
//    Position pawn_pos_vert22  = Position::create_position('a', 4);
//    std::cout <<   board.moveIsValid(pawn_pos0,pawn_pos_vert11)<< std::endl;
//    std::cout <<   board.moveIsValid(pawn_pos0,pawn_pos_vert22)<< std::endl;


    return 0;
}
