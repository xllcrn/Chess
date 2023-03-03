//
// Created by xllcr on 21/02/2023.
//

#include "ChessBoard.h"
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include <memory>
#include <cassert>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
int ChessBoard::m_lines=8;

/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/

/* Default constructor */
ChessBoard::ChessBoard():m_scoreW(0),m_scoreB(0),m_color_active(ColorOfPieces::WHITE){
//  Create the pieces of the chessboard : WHITE
    piecesSet(ColorOfPieces::WHITE);

//  Create the pieces of the chessboard : BLACK
    piecesSet(ColorOfPieces::BLACK);
    std::cout << "---It's white who play---" << std::endl;
}

/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/

void ChessBoard::piecesSet(ColorOfPieces color){
    unsigned int rank, rankp;
    std::string abc{"abcdefgh"};
    switch (color) {
        case ColorOfPieces::WHITE:
            rank = 1;
            rankp= 2;
            break;
        case ColorOfPieces::BLACK:
            rank=8;
            rankp= 7;
            break;
    }
    m_board.insert({Position::create_position('d',rank), std::make_shared<Queen> (Queen(color))});
    // Rooks (tours)
    m_board.insert({Position::create_position('a',rank), std::make_shared<Rook> (Rook(color))});
    m_board.insert({Position::create_position('h',rank), std::make_shared<Rook> (Rook(color))});
    // Knights/Horse (cavaliers)
    m_board.insert({Position::create_position('b',rank), std::make_shared<Knight> (Knight(color))});
    m_board.insert({Position::create_position('g',rank), std::make_shared<Knight> (Knight(color))});
//    // Bishop (fous)
    m_board.insert({Position::create_position('c',rank), std::make_shared<Bishop> (Bishop(color))});
    m_board.insert({Position::create_position('f',rank), std::make_shared<Bishop> (Bishop(color))});
//    // King/queen (roi/reine)
    m_board.insert({Position::create_position('e',rank), std::make_shared<King> (King(color))});
//
//    // Pawn (pions)
    for (char & elem : abc) {
        m_board.insert({Position::create_position(elem,rankp), std::make_shared<Pawn> (Pawn(color))});
    }

}

/* Print chessboard */
std::vector<char> ChessBoard::chessboardToChar() const{
    std::vector<char> print_board(m_lines*m_lines,' ');
    for (auto it = m_board.begin(); it != m_board.end(); ++it){
        Position pos{it->first} ;
        std::shared_ptr<Piece> p_piece{it->second};
        print_board[pos.getCoord()] = p_piece->getType();
    }
    return print_board;
}

/* Print chessboard */
std::string ChessBoard::boardToString(std::vector<char> const & print_board) const{
    std::ostringstream ostr;
    auto icount=1;
    auto num_line=0;
    std::string abc{"  abcdefgh"};

    for (auto& elem : abc){
        ostr << elem << ' ';
    }
    ostr << "\n";
    ostr << "    - - - - - - - - \n";
    auto it_end = print_board.end();
    for(auto i=0;i<m_lines;i++) {
        for (auto it = it_end-(i+1)*m_lines; it != it_end-i*m_lines; it++) {
            if ((icount - 1) % (m_lines) == 0) {
                ostr << (m_lines - num_line) << " | ";
            }
            ostr << *it << ' ';
            if (icount % m_lines == 0) {
                ostr << "| " << (m_lines - num_line);
                ostr << "\n";
                num_line++;
            }
            icount++;
        }
    }
    ostr << "    - - - - - - - - \n";
    for (auto& elem : abc){
        ostr << elem << ' ';
    }
    ostr << "\n";

    return ostr.str();
}


/* Move a piece */
void ChessBoard::movePiece(Position const & pBefore, Position const & pAfter){

//    try{
        bool valid = true;
        // check : if there is a piece at position before
        if(m_board.find(pBefore) == m_board.end()){
//            throw std::runtime_error("MOVE IS NOT VALID : no piece found at that position");
            valid = false;
        }

        // take the piece to move
        std::shared_ptr<Piece> p_piece;
        p_piece = m_board[pBefore];

        // check : the good color active
        ColorOfPieces color = p_piece->getColor();
        if (color!=m_color_active){
            valid = false;
        }

        // Movement

        trajectory pathVector;
        pathVector = p_piece->drawTraject(pBefore);
        pathVector = correctTraject(pathVector, pAfter);

        if (!pathVector.empty() && valid) {
// a piece is at pAfter
            if (m_board.find(pAfter) != m_board.end()) {
                std::shared_ptr<Piece> p_piece_after;
                p_piece_after = m_board[pAfter];
                if (p_piece->getColor() == p_piece_after->getColor()) {
                    valid = false;
//                    throw std::runtime_error(
//                            "MOVE IS NOT VALID : a piece cannot move into a position where a piece of the same color is present");
                } else {
                    setScore(p_piece_after->getValue(), p_piece->getColor());
                    m_board.erase(pBefore);
                    m_board.erase(pAfter);
                    m_board[pAfter] = p_piece;
                }
            } else {
                m_board.erase(pBefore);
                m_board[pAfter] = p_piece;
            }
        } else {
//            throw std::runtime_error("MOVE IS NOT VALID : movement not conform to piece rules");
            valid = false;
        }

        // everything should be ok at that point
        if (valid) {
            p_piece-> setMoved();
            switch_color(m_color_active);
            if (m_color_active==ColorOfPieces::WHITE)std::cout << "---It's white who play---" << std::endl;
            if (m_color_active==ColorOfPieces::BLACK)std::cout << "---It's black who play---" << std::endl;
        }
//    }catch(const std::runtime_error &e){
//        std::cerr << e.what() << std::endl;
//    }
}

/* Show possibilities */
void ChessBoard::moveHelp(Position const & pBefore) {
    if(m_board.find(pBefore) == m_board.end()){
        std::cout << "No piece found at that position";
        return;
    }

    std::shared_ptr<Piece> p_piece;
    p_piece = m_board[pBefore];
    trajectory pathVector;
    pathVector = p_piece->drawTraject(pBefore);
    pathVector = correctTraject(pathVector);
    std::cout << "All possible moves for the piece" << std::endl;
    std::cout << *p_piece << std::endl;
    for (auto paths : pathVector) {
        for (auto pos : paths) {
            std::cout << pos;
        }
    }

    std::vector<char> print_board{chessboardToChar()};
//  if trajectory for help
    if(!pathVector.empty()) {
        for (auto paths : pathVector) {
            for (auto pos : paths) {
                print_board[pos.getCoord()] = 'x';
            }
        }
    }
    std::cout << boardToString(print_board);
}

trajectory ChessBoard::correctTraject(trajectory const & traject) const{
    std::shared_ptr<Piece> p_piece_trj;
    trajectory new_traject;
    path new_path;

    // loop on paths
    for (path const & path1 : traject) {
        new_path.clear();
        // loop on positions
        for (Position const & pos : path1) {
            if (m_board.find(pos) == m_board.end()) {
                // position not found : position is free
                new_path.push_back(pos);
            } else {
                // position found : position is occupied
                break;
            }
        }
        new_traject.insert(new_path);
    }
    return new_traject;
}

trajectory ChessBoard::correctTraject(trajectory const & traject, Position const & pAfter) const{
    std::shared_ptr<Piece> p_piece_trj;
    trajectory new_traject;
    path new_path;

    // loop on paths
    for (path const & path1 : traject) {
        new_path.clear();
        // loop on positions
        for (Position const & pos : path1) {
            if (m_board.find(pos) == m_board.end()) {
                // position not found : position is free
                new_path.push_back(pos);
            } else {
                // position found : position is occupied
                // it's the piece I will win!
                if(pos==pAfter){
                    new_path.push_back(pos);
                    break;
                }
                else {
//                    std::cout << "an object has been found" << std::endl;
                    break;
                }
            }
        }
        // is pAfter in the path?
        if(std::find(new_path.begin(), new_path.end(), pAfter) != new_path.end()){
            new_traject.insert(new_path);
        }
    }
    return new_traject;
}

void ChessBoard::setScore(int const & value, ColorOfPieces const & color){
    switch (color){
        case ColorOfPieces::WHITE:
            m_scoreW += value;
            break;
        case ColorOfPieces::BLACK:
            m_scoreB += value;
            break;
    }
}

int ChessBoard::getScoreW(){
    return m_scoreW;
}
int ChessBoard::getScoreB(){
    return m_scoreB;
}

void ChessBoard::printScores(){
    std::cout << "The score of WHITE is : " << m_scoreW << std::endl;
    std::cout << "The score of BLACK is : " << m_scoreB << std::endl;
}

void ChessBoard::switch_color(ColorOfPieces color) {
    switch (color) {
        case ColorOfPieces::WHITE:
            m_color_active = ColorOfPieces::BLACK;
            break;
        case ColorOfPieces::BLACK:
            m_color_active = ColorOfPieces::WHITE;
            break;
    }
}
/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, ChessBoard& p){
    std::vector<char> print_board;
    print_board = p.chessboardToChar();
    os << p.boardToString(print_board);
    return os;
}