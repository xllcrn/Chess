// TODO: Include your class to test here.
#include "../include/ChessModel.h"
#include "C:/Users/xllcr/Documents/C++/Chess/include/Position.h"
#define BOOST_TEST_MODULE MyTest
#include <C:\boost_1_81_0\boost_1_81_0\boost\test\unit_test.hpp>


BOOST_AUTO_TEST_SUITE(chess)
//    BOOST_AUTO_TEST_CASE(piece_position)
//    {
//        ChessBoard board("000rh0kP/rp00p0pq/0PqP0P0P/8/8/8/8/RQH0K0R0");
//        Position pos1= Position::create('d',1);
//        BOOST_CHECK_EQUAL('r', board.getPieceType(pos1));
//
//        Position pos2= Position::create('b',8);
//        BOOST_CHECK_EQUAL('Q', board.getPieceType(pos2));
//
//        Position pos3= Position::create('f',3);
//        BOOST_CHECK_EQUAL('P', board.getPieceType(pos3));
//
//    }

    BOOST_AUTO_TEST_CASE(queen_move_isvalid)
    {
        ChessModel board("8/8/00q00000/8/8/8/00P00000/8");
        Position queen_pos= Position::create('c',3);
        Position queen_pos_diag1= Position::create('g',7);
        Position queen_pos_diag2= Position::create('e',1);
        Position queen_pos_vert1= Position::create('c',1);
        Position queen_pos_vert2= Position::create('c',6);
        Position queen_pos_vert4= Position::create('c',7);
        Position queen_pos_vert3= Position::create('c',8);
        Position queen_pos_hori1= Position::create('a',3);
        Position queen_pos_hori2= Position::create('h',3);
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move {queen_pos,queen_pos},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_diag1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_diag2},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_vert1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_vert2},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_hori1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_hori2},Color::WHITE));
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move {queen_pos,queen_pos_vert3},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move {queen_pos,queen_pos_vert4},Color::WHITE));
    }

    BOOST_AUTO_TEST_CASE(queen_move)
    {
        ChessModel board("00q00000/8/8/8/00Q00000/8/00P00000/8");
        Position queenW_pos0= Position::create('c',1);
        Position queenW_pos1= Position::create('a',3);
        Position queenB_pos0= Position::create('c',5);
        Position queenB_pos1= Position::create('c',3);
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{queenW_pos0,queenW_pos1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{queenB_pos0,queenB_pos1},Color::BLACK));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{queenW_pos0,queenB_pos0},Color::WHITE));
    }


    BOOST_AUTO_TEST_CASE(king_move_isvalid) {
        ChessModel board("8/8/8/000Pk000/8/8/00P00000/8");
        Position king_pos = Position::create('e', 4);
        Position king_pos_hori1 = Position::create('d', 4);
        Position king_pos_hori2 = Position::create('f', 4);
        Position king_pos_vert1 = Position::create('e', 3);
        Position king_pos_vert2 = Position::create('e', 5);
        Position king_pos_diag1 = Position::create('d', 5);
        Position king_pos_diag2 = Position::create('f', 5);
        Position king_pos_diag3 = Position::create('d', 3);
        Position king_pos_diag4 = Position::create('f', 3);
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_hori1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_hori2},Color::WHITE));
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{king_pos,king_pos_vert1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_vert2},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_diag1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_diag2},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_diag3},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{king_pos,king_pos_diag4},Color::WHITE));
    }
//
    BOOST_AUTO_TEST_CASE(pawn_move_isvalid) {
        ChessModel board("8/pp000000/8/000pq000/0000P000/8/00P00000/8");
        Position pawn_pos0= Position::create('a', 2);
        Position pawn_pos = Position::create('d', 4);
        Position pawn_pos_vert3 = Position::create('d', 3);
        Position pawn_pos_vert1 = Position::create('d', 5);
        Position pawn_pos_vert2 = Position::create('d', 6);
        Position pawn_pos_diag1 = Position::create('c', 5);
        Position pawn_pos_diag2 = Position::create('e', 5);
        Position pawn_pos_vert11  = Position::create('a', 3);
        Position pawn_pos_vert22  = Position::create('a', 4);
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{pawn_pos,pawn_pos},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{pawn_pos,pawn_pos_vert1},Color::WHITE));
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{pawn_pos,pawn_pos_vert2},Color::WHITE));
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{pawn_pos,pawn_pos_vert3},Color::WHITE));
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{pawn_pos,pawn_pos_diag1},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{pawn_pos,pawn_pos_diag2},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{pawn_pos0,pawn_pos_vert11},Color::WHITE));
        BOOST_CHECK_EQUAL(true, board.isMoveValid(Move{pawn_pos0,pawn_pos_vert22},Color::WHITE));
        ChessModel board2("0000k000/pppppppp/8/000pq000/Q000P000/8/00P00000/8");
        Position pawn_pos2 = Position::create('d', 2);
        BOOST_CHECK_EQUAL(false, board.isMoveValid(Move{pawn_pos2,pawn_pos},Color::WHITE));
    }
//
    BOOST_AUTO_TEST_CASE(chess_test) {
//        ChessBoard board("8/8/8/0000k000/8/8/00P0Q000/8");
//        BOOST_CHECK_EQUAL(true, board.isChessMate(ChessMateChoice::CHESS,'k'));
//        ChessBoard board2("8/8/8/0000k000/8/8/00P000R0/8");
//        BOOST_CHECK_EQUAL(false, board2.isChessMate(ChessMateChoice::CHESS,'k'));
        ChessModel board3("8/8/000ppp00/000pkp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(Color::BLACK, board3.checkWinner());
//        ChessBoard board4("8/8/8/0000k00r/8/8/00P000R0/8");
//        BOOST_CHECK_EQUAL(false, board4.isChessMate(ChessMateChoice::CHESS,'k'));
    }
//
    BOOST_AUTO_TEST_CASE(mate_test) {
        ChessModel board0("8/8/000ppp00/Q000kp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(Color::BLACK, board0.checkWinner());
        // mat a l'etouffee
        ChessModel board1("8/8/8/8/8/8/00000hPP/000000RK");
        BOOST_CHECK_EQUAL(Color::WHITE, board1.checkWinner());
        // mat de Boden
        ChessModel board2("8/8/8/00000b00/8/b0000000/P00H0000/00KR0000");
        BOOST_CHECK_EQUAL(Color::WHITE, board2.checkWinner());
        // mat de Lolli
        ChessModel board3("8/8/8/8/8/00000pP0/00000PqP/00000RK0");
        BOOST_CHECK_EQUAL(Color::WHITE, board3.checkWinner());
        // mat du gueridon
        ChessModel board4("8/8/8/8/000p0000/0000q000/0000K000/000R0B00");
        BOOST_CHECK_EQUAL(Color::WHITE, board4.checkWinner());
    }

    BOOST_AUTO_TEST_CASE(chessmate_test) {
        ChessModel board("8/8/000ppp00/Q000kp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(Color::BLACK, board.checkWinner());
    }
//
//    BOOST_AUTO_TEST_CASE(castling_test) {
//        // short castling white
//        ChessBoard short_board1("rhbqk00r/pppp0ppp/00000h00/00b0p000/00B0P000/00H00000/PPPP0PPP/R0BQK0HR");
//        Position king_pos  = Position::create('e', 1);
//        Position king_pos1  = Position::create('g', 1);
//        Position rook_pos1  = Position::create('f', 1);
//        short_board1.movePiece(king_pos,king_pos1);
//        BOOST_CHECK_EQUAL('k', short_board1.getPieceType(king_pos1));
//        BOOST_CHECK_EQUAL('r', short_board1.getPieceType(rook_pos1));
//        // short castling black
//        ChessBoard short_board2("r000kbhr/pbppqppp/00h00000/0000p000/00B0P000/00HP0H00/PPP00PPP/R0BQK00R",'b');
//        Position King_pos   = Position::create('e', 8);
//        Position King_pos1  = Position::create('g', 8);
//        Position Rook_pos1  = Position::create('f', 8);
//        short_board2.movePiece(King_pos,King_pos1);
//        BOOST_CHECK_EQUAL('K', short_board2.getPieceType(King_pos1));
//        BOOST_CHECK_EQUAL('R', short_board2.getPieceType(Rook_pos1));
//        // long castling white
//        Position king_posl  = Position::create('c', 1);
//        Position rook_posl  = Position::create('d', 1);
//        short_board2.movePiece(king_pos,king_posl);
//        BOOST_CHECK_EQUAL('k', short_board2.getPieceType(king_posl));
//        BOOST_CHECK_EQUAL('r', short_board2.getPieceType(rook_posl));
//    }

BOOST_AUTO_TEST_SUITE_END()
