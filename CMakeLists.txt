cmake_minimum_required(VERSION 3.16)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp ChessBoard.cpp ChessBoard.h Position.cpp Position.h Piece.cpp Piece.h Queen.cpp Queen.h Player.cpp Player.h Rook.cpp Rook.h Bishop.cpp Bishop.h King.cpp King.h Knight.cpp Knight.h Pawn.cpp Pawn.h)