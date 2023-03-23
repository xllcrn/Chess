
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
#include <array>
#include <GeneralTree.h>
#include <ChessMoveTree.h>

int main() {

//    ChessBoard board0("8/8/000ppp00/Q000kp00/000ppp00/00000H00/00P000R0/8");
//    std::cout << board0;
//    board0.moveHelp(Position::create_position('e', 4));
////
//////    // mat a l'etouffee
//    ChessBoard board1("8/8/8/8/8/8/00000hPP/000000RK");
//    std::cout << board1;
//    board1.moveHelp(Position::create_position('h', 8));
//////    BOOST_CHECK_EQUAL(true, board1.isMate('K'));
//////    // mat de Boden
//    ChessBoard board2("8/8/8/00000b00/8/b0000000/P00H0000/00KR0000");
//    std::cout << board2;
//    board2.moveHelp(Position::create_position('c', 8));
//
//
//
////    // mat de Lolli
//    ChessBoard board3("8/8/8/8/8/00000pP0/00000PqP/00000RK0");
//    std::cout << board3;
//    board3.moveHelp(Position::create_position('g', 8));
////    // mat du gueridon
////    ChessBoard board4("8/8/8/8/000p0000/0000q000/0000K000/000R0B00");
////    BOOST_CHECK_EQUAL(true, board4.isMate('K'));


//    ChessBoard board("8/8/8/000Pk000/000P0000/8/00P00000/8");
//    std::cout << board;
//    board.moveHelp(Position::create_position('e', 4));



//    ChessBoard board("r000kbhr/pbppqppp/00h00000/0000p000/00B0P000/00HP0H00/PPP00PPP/R0BQK00R",'b');
//    std::cout << board;
//    char letter_init;
//    int number_init;
//    char letter_fin;
//    int number_fin;
//    bool move;
//    while (!board.isChessMate()){
//        move = false;
//        std::cout << "Move a piece : " << std::endl;
//        std::cout << "Give initial position : " << std::endl;
//        while(!( std::cin >> letter_init >> number_init) ){
//            std::cout << "Please, give a letter, followed by an integer" << std::endl;
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//        Position pos_init  = Position::create_position(letter_init, number_init);
//
//        std::cout << "Give final position : " << std::endl;
//        while(!( std::cin >> letter_fin >> number_fin) ){
//            std::cout << "Please, give a letter, followed by an integer" << std::endl;
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//        Position pos_fin  = Position::create_position(letter_fin, number_fin);
//        move = board.movePiece(pos_init,pos_fin);
//        if (!move) std::cout << "Piece has NOT moved, please try again!" << std::endl;
//        std::cout << board;
//    }


    // recuperer les moves potentiels
//    ChessBoard board("8/8/0kq00000/8/8/8/0KQ00000/8");
//    std::vector<aMove> vectMoves;
//    aMove am(Position::create_init_position(), Position::create_init_position());
//    vectMoves.emplace_back(am);
//    vectMoves = board.potentialMoves('w');
//    std::cout << board;
//    for (auto const &move : vectMoves) {
//        std::cout << move << std::endl;
//    }
//    // level 0
//    std::shared_ptr<Node<aMove>> root = newNode<aMove>(am);
//    for (auto const &move : vectMoves) {
//        (root->child).push_back(newNode<aMove>(move));
//    }
//    // level 1
//    for (auto const &toddler : root->child){
//        (toddler->child).push_back(newNode<aMove());
//    }

//    std::shared_ptr<Node<int>> root = newNode<int>(10);
//    (root->child).push_back(newNode<int>(2));
//    (root->child).push_back(newNode<int>(34));
//    (root->child).push_back(newNode<int>(56));
//    (root->child).push_back(newNode<int>(100));
//    (root->child[0]->child).push_back(newNode<int>(77));
//    (root->child[0]->child).push_back(newNode<int>(88));
//    (root->child[2]->child).push_back(newNode<int>(1));
//    (root->child[3]->child).push_back(newNode<int>(7));
//    (root->child[3]->child).push_back(newNode<int>(8));
//    (root->child[3]->child).push_back(newNode<int>(9));
////  pass the root node of your binary tree
//    std::cout <<root;
//    std::cout << "Level order traversal Before Mirroring\n";
//    LevelOrderTraversal(root);
//
//    // avec create_tree
//    ChessBoard board_root0("xxxxxxxx/xxxxxxxx/xxxxxxxx/xxk0xxxx/xx000xxx/xxx0Kxxx/xxxxxxxx/xxxxxxxx");
//    std::cout << board_root0;
//    ChessMove am0(Position::create_init_position(), Position::create_init_position(),'0');
//    std::shared_ptr<Node<ChessMove>> root0 = newNode<ChessMove>(am0);
//    createTree( root0, 1, board_root0);
//    LevelOrderTraversal(root0);
////
////
////    //avec recursive
    ChessBoard board_root1("xxxxxxxx/xxxxxxxx/xxxxxxxx/xxr0xxxx/xx000xxx/xxx0Kxxx/xxxxxxxx/xxxxxxxx");
    std::cout << board_root1;
//    ChessMove am1(Position::create_init_position(), Position::create_init_position(), '0');
    std::shared_ptr<Node<ChessMove>> root1 = newNode<ChessMove>();
//    createTree( root1, 1, board_root1);
    recursiveTree(root1, 4, board_root1, ColorOfPieces::WHITE) ;
//    LevelOrderTraversal(root1);
//    printBranches<ChessMove>(root1);
    std::cout << root1;


//    ChessBoard short_board1("rhbqk00r/pppp0ppp/00000h00/00b0p000/00B0P000/00H00000/PPPP0PPP/R0BQK0HR",'b');
//    std::cout << short_board1;
//    Position king_pos  = Position::create_position('e', 1);
//    Position king_pos1  = Position::create_position('g', 1);
//    Position rook_pos1  = Position::create_position('f', 1);
//    short_board1.movePiece(king_pos,king_pos1);
//    std::cout << short_board1;



//// graph implementation
//    // graph edges array.
//    std::vector<std::shared_ptr<int>> vectInt;
//    vectInt.emplace_back(std::make_shared<int> (0));
//    vectInt.emplace_back(std::make_shared<int> (1));
//    vectInt.emplace_back(std::make_shared<int> (2));
//    vectInt.emplace_back(std::make_shared<int> (3));
//    vectInt.emplace_back(std::make_shared<int> (4));
//    std::vector<graphEdge<int>> edges;
//
////    graphEdge edges[] = {
////            // (x, y, w) -> edge from x to y with weight w
////            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
////    };
//    edges.emplace_back(graphEdge<int>{vectInt[0],vectInt[1],2}) ;
//    edges.emplace_back(graphEdge<int>{vectInt[0],vectInt[2],4}) ;
//    edges.emplace_back(graphEdge<int>{vectInt[1],vectInt[4],3}) ;
////    edges.emplace_back(graphEdge<int>{2,3,2}) ;
////    edges.emplace_back(graphEdge<int>{3,1,4}) ;
////    edges.emplace_back(graphEdge<int>{4,3,3}) ;
//            // (x, y, w) -> edge from x to y with weight w
//    int N = 6;      // Number of vertices in the graph
//    // calculate number of edges
////    int n = sizeof(edges)/sizeof(edges[0]);
//    // construct graph
//    int n=3;
//    DiaGraph diagraph(edges, n, N);
//    // print adjacency list representation of graph
//    std::cout<<"Graph adjacency list "<<std::endl<<"(start_vertex, end_vertex, weight):"<<std::endl;
//    for (int i = 0; i < N; i++)
//    {
//        // display adjacent vertices of vertex i
//        display_AdjList(diagraph.head[i], i);
//    }

    //    ChessBoard short_board2("r000kbhr/pbppqppp/00h00000/0000p000/00B0P000/00HP0H00/PPP00PPP/R0BQK00R");
//    Position king_pos  = Position::create_position('e', 1);
//
//    Position king_posl  = Position::create_position('c', 1);
//    Position rook_posl  = Position::create_position('d', 1);
//    short_board2.movePiece(king_pos,king_posl);
//
//    std::cout << short_board2;

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
