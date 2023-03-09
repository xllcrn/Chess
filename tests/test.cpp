//
// Created by xllcr on 03/03/2023.
//
// TODO: Include your class to test here.
#include "../include/ChessBoard.h"
#include "C:/Users/xllcr/Documents/C++/Chess/include/Position.h"
#define BOOST_TEST_MODULE MyTest
#include <C:\boost_1_81_0\boost_1_81_0\boost\test\unit_test.hpp>


BOOST_AUTO_TEST_SUITE(chess)
    BOOST_AUTO_TEST_CASE(piece_position)
    {
        ChessBoard board("000rh0kP/rp00p0pq/0PqP0P0P/8/8/8/8/RQH0K0R0");
        Position pos1= Position::create_position('d',1);
        BOOST_CHECK_EQUAL('r', board.getPieceType(pos1));

        Position pos2= Position::create_position('b',8);
        BOOST_CHECK_EQUAL('Q', board.getPieceType(pos2));

        Position pos3= Position::create_position('f',3);
        BOOST_CHECK_EQUAL('P', board.getPieceType(pos3));

    }

    BOOST_AUTO_TEST_CASE(queen_move_isvalid)
    {
        ChessBoard board("8/8/00q00000/8/8/8/00P00000/8");
        Position queen_pos= Position::create_position('c',3);
        Position queen_pos_diag1= Position::create_position('g',7);
        Position queen_pos_diag2= Position::create_position('e',1);
        Position queen_pos_vert1= Position::create_position('c',1);
        Position queen_pos_vert2= Position::create_position('c',6);
        Position queen_pos_vert4= Position::create_position('c',7);
        Position queen_pos_vert3= Position::create_position('c',8);
        Position queen_pos_hori1= Position::create_position('a',3);
        Position queen_pos_hori2= Position::create_position('h',3);
        BOOST_CHECK_EQUAL(false, board.moveIsValid(queen_pos,queen_pos));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_diag2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_hori1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_hori2));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(queen_pos,queen_pos_vert3));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert4));
    }
    BOOST_AUTO_TEST_CASE(queen_move)
    {
        ChessBoard board("00q00000/8/8/8/00Q00000/8/00P00000/8");
        Position queenW_pos0= Position::create_position('c',1);
        Position queenW_pos1= Position::create_position('a',3);
        Position queenB_pos0= Position::create_position('c',5);
        Position queenB_pos1= Position::create_position('c',3);
        board.movePiece(queenW_pos0,queenW_pos1);
        BOOST_CHECK_EQUAL('q', board.getPieceType(queenW_pos1));
        board.movePiece(queenB_pos0,queenB_pos1);
        BOOST_CHECK_EQUAL('Q', board.getPieceType(queenB_pos1));
        board.movePiece(queenW_pos1,queenB_pos1);
        BOOST_CHECK_EQUAL('q', board.getPieceType(queenB_pos1));
    }


    BOOST_AUTO_TEST_CASE(king_move_isvalid) {
        ChessBoard board("8/8/8/000Pq000/8/8/00P00000/8");
        Position king_pos = Position::create_position('e', 4);
        Position king_pos_hori1 = Position::create_position('d', 4);
        Position king_pos_hori2 = Position::create_position('f', 4);
        Position king_pos_vert1 = Position::create_position('e', 3);
        Position king_pos_vert2 = Position::create_position('e', 5);
        Position king_pos_diag1 = Position::create_position('d', 5);
        Position king_pos_diag2 = Position::create_position('f', 5);
        Position king_pos_diag3 = Position::create_position('d', 3);
        Position king_pos_diag4 = Position::create_position('f', 3);
        BOOST_CHECK_EQUAL(false, board.moveIsValid(king_pos,king_pos));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_hori1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_hori2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_vert1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_vert2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag3));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag4));
    }

    BOOST_AUTO_TEST_CASE(pawn_move_isvalid) {
        ChessBoard board("8/pp000000/8/000pq000/0000P000/8/00P00000/8");
        Position pawn_pos0= Position::create_position('a', 2);
        Position pawn_pos = Position::create_position('d', 4);
        Position pawn_pos_vert3 = Position::create_position('d', 3);
        Position pawn_pos_vert1 = Position::create_position('d', 5);
        Position pawn_pos_vert2 = Position::create_position('d', 6);
        Position pawn_pos_diag1 = Position::create_position('c', 5);
        Position pawn_pos_diag2 = Position::create_position('e', 5);
        Position pawn_pos_vert11  = Position::create_position('a', 3);
        Position pawn_pos_vert22  = Position::create_position('a', 4);
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos,pawn_pos_vert1));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos_vert2));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos_vert3));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos,pawn_pos_diag2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos0,pawn_pos_vert11));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos0,pawn_pos_vert22));
    }

    BOOST_AUTO_TEST_CASE(chess_test) {
        ChessBoard board("8/8/8/0000k000/8/8/00P0Q000/8");
        BOOST_CHECK_EQUAL(true, board.isChess('k'));
        ChessBoard board2("8/8/8/0000k000/8/8/00P000R0/8");
        BOOST_CHECK_EQUAL(false, board2.isChess('k'));
        ChessBoard board3("8/8/000ppp00/000pkp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(true, board.isChess('k'));
        ChessBoard board4("8/8/8/0000k00r/8/8/00P000R0/8");
        BOOST_CHECK_EQUAL(false, board4.isChess('k'));
    }

    BOOST_AUTO_TEST_CASE(mate_test) {
        ChessBoard board("8/8/000ppp00/Q000kp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(true, board.isMate('k'));
    }

    BOOST_AUTO_TEST_CASE(chessmate_test) {
        ChessBoard board("8/8/000ppp00/Q000kp00/000ppp00/00000H00/00P000R0/8");
        BOOST_CHECK_EQUAL(true, board.isMate('k'));
        BOOST_CHECK_EQUAL(true, board.isChessMate());
    }

BOOST_AUTO_TEST_SUITE_END()
