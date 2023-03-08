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
        BOOST_CHECK_EQUAL('r', board.getPiece(pos1)->getType());
        BOOST_CHECK_EQUAL(static_cast<int>(ColorOfPieces::WHITE), static_cast<int>(board.getPiece(pos1)->getColor()));

        Position pos2= Position::create_position('b',8);
        BOOST_CHECK_EQUAL('Q', board.getPiece(pos2)->getType());
        BOOST_CHECK_EQUAL(static_cast<int>(ColorOfPieces::BLACK), static_cast<int>(board.getPiece(pos2)->getColor()));

        Position pos3= Position::create_position('f',3);
        BOOST_CHECK_EQUAL('P', board.getPiece(pos3)->getType());
        BOOST_CHECK_EQUAL(static_cast<int>(ColorOfPieces::BLACK), static_cast<int>(board.getPiece(pos3)->getColor()));

    }

    BOOST_AUTO_TEST_CASE(queen_displacement)
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
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_diag2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_hori1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_hori2));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(queen_pos,queen_pos_vert3));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(queen_pos,queen_pos_vert4));
    }

    BOOST_AUTO_TEST_CASE(king_displacement) {
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
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_hori1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_hori2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_vert1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_vert2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag2));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag3));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(king_pos,king_pos_diag4));
    }

    BOOST_AUTO_TEST_CASE(pawn_displacement) {
        ChessBoard board("8/8/8/000pq000/0000P000/8/00P00000/8");
        Position pawn_pos = Position::create_position('d', 4);
        Position pawn_pos_vert3 = Position::create_position('d', 3);
        Position pawn_pos_vert1 = Position::create_position('d', 5);
        Position pawn_pos_vert2 = Position::create_position('d', 6);
        Position pawn_pos_diag1 = Position::create_position('c', 5);
        Position pawn_pos_diag2 = Position::create_position('e', 5);
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos,pawn_pos_vert1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos,pawn_pos_vert2));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos_vert3));
        BOOST_CHECK_EQUAL(false, board.moveIsValid(pawn_pos,pawn_pos_diag1));
        BOOST_CHECK_EQUAL(true, board.moveIsValid(pawn_pos,pawn_pos_diag2));
    }

    BOOST_AUTO_TEST_SUITE_END()
