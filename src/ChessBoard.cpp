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
ChessBoard::ChessBoard():m_scoreW(0),m_scoreB(0),m_color_active(ColorOfPieces::WHITE),
                         m_kingW(Position::create_position('e',1)),m_kingB(Position::create_position('e',8)){
    //  Create the pieces of the chessboard : WHITE
    piecesSet("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
//  Create the pieces of the chessboard : BLACK
    std::cout << "---It's white who play---" << std::endl;
}

ChessBoard::ChessBoard(std::string const & boardData):m_scoreW(0),m_scoreB(0),m_color_active(ColorOfPieces::WHITE),
                                                      m_kingW(Position::create_position('e',1)),m_kingB(Position::create_position('e',8)){
//  Create the pieces of the chessboard
    piecesSet(boardData);
    std::cout << "---It's white who play---" << std::endl;
}
/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
void ChessBoard::piecesSet(std::string const & boardData){
    auto rank=1;
    auto i=-1;
    ColorOfPieces color=ColorOfPieces::WHITE;
    std::string abc{"abcdefgh"};
    std::string type{"rhbqkpRHBQKP"};
    for (auto const & C : boardData){
        ++i;
        if(std::isdigit(C)) continue;
        std::size_t found = type.find(C);
        if (found!=std::string::npos){
            if (rank>8) assert("Bad string initialization to set boardchess pieces. Too much characters");
            color=ColorOfPieces::WHITE;
            if (isupper(C)) color=ColorOfPieces::BLACK;
            char c = tolower(C);
            if(c=='q') m_board.insert({Position::create_position(abc[i],rank), std::make_shared<Queen> (Queen(color))});
            if(c=='r') m_board.insert({Position::create_position(abc[i],rank), std::make_shared<Rook> (Rook(color))});
            if(c=='b') m_board.insert({Position::create_position(abc[i],rank), std::make_shared<Bishop> (Bishop(color))});
            if(c=='h') m_board.insert({Position::create_position(abc[i],rank), std::make_shared<Knight> (Knight(color))});
            if(c=='p') m_board.insert({Position::create_position(abc[i],rank), std::make_shared<Pawn> (Pawn(color))});
            if(c=='k') {
                m_board.insert({Position::create_position(abc[i], rank), std::make_shared<King>(King(color))});
                setKingPosition(Position::create_position(abc[i], rank), color);
            }
        }
        else if (C=='/'){
            i = -1;
            ++rank;
        }
        else{
            assert("Bad string initialization to set boardchess pieces");
        }
    }
}


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

    bool valid = moveIsValid(pBefore,pAfter);
    if (!valid){
        std::cout << "Displacement is NOT VALID" << std::endl;
        return;
    }

    // take the piece to move
    std::shared_ptr<Piece> p_piece;
    p_piece = m_board[pBefore];
    // is there a piece at the final position?
    std::shared_ptr<Piece> p_piece_after;
    bool isPieceAfter = false;
    if (m_board.find(pAfter) != m_board.end()){
        isPieceAfter=true;
        p_piece_after = m_board[pAfter];
    }

    // a piece is at pAfter
    if (isPieceAfter) {
        setScore(p_piece_after->getValue(), p_piece->getColor());
        m_board.erase(pBefore);
        m_board.erase(pAfter);
        m_board[pAfter] = p_piece;
    } else {
        m_board.erase(pBefore);
        m_board[pAfter] = p_piece;
    }
    p_piece-> setMoved();
//    if(p_piece->getType()=='k') setKingPosition(pAfter, m_color_active);
    switch_color(m_color_active);
    if (m_color_active==ColorOfPieces::WHITE)std::cout << "---It's white who play---" << std::endl;
    if (m_color_active==ColorOfPieces::BLACK)std::cout << "---It's black who play---" << std::endl;

}


/* Move a piece */
bool ChessBoard::moveIsValid(Position const & pBefore, Position const & pAfter){

    bool valid = true;

    /*          check : is a piece at initial position ?
    ***************************************************/
    if(m_board.find(pBefore) == m_board.end()){
        return false;
    }

    // take the piece to move
    std::shared_ptr<Piece> p_piece;
    p_piece = m_board[pBefore];
    // is there a piece at the final position?
    std::shared_ptr<Piece> p_piece_after;
    bool isPieceAfter = false;
    if (m_board.find(pAfter) != m_board.end()){
        isPieceAfter=true;
        p_piece_after = m_board[pAfter];
    }

    /*          check : the right color to play ?
    ***************************************************/
    ColorOfPieces color = p_piece->getColor();
    if (color!=m_color_active){
        return false;
    }

    /*          check : piece before & after of different color ?
    **************************************************************/
    if (isPieceAfter) {
        if (p_piece->getColor() == p_piece_after->getColor()) {
            return false;
        }
    }

    // Displacement
    trajectory pathVector;
    pathVector = p_piece->drawTraject(pBefore,isPieceAfter);
    pathVector = correctTraject(pathVector, pAfter);

    /*          check : is there a path ?
     ***************************************************/
    if (pathVector.empty()) {
        return false;
        //            throw std::runtime_error("MOVE IS NOT VALID : movement not conform to piece rules");
    }

    return true;
}



//bool Chessboard::CheckMate(){
//    // check if the king of the activate color is checkmate
//    // boucle sur toutes les pieces de l'autre couleur
//    // le roi doit etre attaque de toute part, quoiqu'il fasse
//    // s'il est attaque sur sa position de depart : il doit bouger
//    // 1) verifier s'il peut se sauver
//    // 2) verifier si aucune autre piece peut le sauver
//    // s'il est attaque sur toutes les autres positions possibles et qu'aucune piece ne peut l'aider: c'est echec et mat
//
//    // 1) le roi est il attaque?
//    // reperer le roi... a tout moment conserver les positions des rois en memoire!
//    // loop sur les pieces de l'autre couleur et on voit si elles peuvent se positionner sur le roi
//    for (auto const & p_piece : m_board){
//        p_piece.second->
//    }
//    std::shared_ptr<Piece> p_piece;
//    p_piece = m_board[pBefore];
//
//}

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
                new_path.push_back(pos);
                break;
            }
        }
        new_traject.insert(new_path);
    }
    return new_traject;
}

trajectory ChessBoard::correctTraject(trajectory const & traject, Position const & pAfter) const{
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

std::shared_ptr<Piece> ChessBoard::getPiece(Position const & pos) {
    return m_board[pos];
}

ColorOfPieces ChessBoard::getPieceColor(Position const & pos) {
    return m_board[pos]->getColor();
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

void ChessBoard::setKingPosition(const Position &pos, const ColorOfPieces &color) {
    switch (color) {
        case ColorOfPieces::WHITE:
            m_kingW = pos;
            break;
        case ColorOfPieces::BLACK:
            m_kingB = pos;
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