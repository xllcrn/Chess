
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



    ChessBoard board("8/pp000000/8/000pq000/0000P000/8/00P00000/8");
    Position pawn_pos = Position::create_position('d', 4);
    Position pawn_pos_vert3 = Position::create_position('d', 3);
    Position pawn_pos_vert1 = Position::create_position('d', 5);
    Position pawn_pos_vert2 = Position::create_position('d', 6);
    Position pawn_pos_diag1 = Position::create_position('c', 5);
    Position pawn_pos_diag2 = Position::create_position('e', 5);
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos)<< std::endl;
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert1)<< std::endl;
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert2)<< std::endl; //ici
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_vert3)<< std::endl;
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_diag1)<< std::endl;
    std::cout <<  board.moveIsValid(pawn_pos,pawn_pos_diag2)<< std::endl;

    Position pawn_pos0= Position::create_position('a', 2);
    Position pawn_pos_vert11  = Position::create_position('a', 3);
    Position pawn_pos_vert22  = Position::create_position('a', 4);
    std::cout <<   board.moveIsValid(pawn_pos0,pawn_pos_vert11)<< std::endl;
    std::cout <<   board.moveIsValid(pawn_pos0,pawn_pos_vert22)<< std::endl;


    return 0;
}
