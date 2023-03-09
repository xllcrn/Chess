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

/// @brief Default constructor
///
ChessBoard::ChessBoard():m_scoreW(0),
                         m_scoreB(0),
                         m_color_active(ColorOfPieces::WHITE),
                         m_kingW(Position::create_position('e',1)),
                         m_kingB(Position::create_position('e',8)){
    //  Create the pieces of the chessboard : WHITE
    piecesSet("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
//  Create the pieces of the chessboard : BLACK
    std::cout << "---It's white who play---" << std::endl;
}

/// @brief Constructor from a string
/// @param string describing how the chessboard is filled (example : "rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")
///
ChessBoard::ChessBoard(std::string const & boardData):m_scoreW(0),
                                                      m_scoreB(0),
                                                      m_color_active(ColorOfPieces::WHITE),
                                                      m_kingW(Position::create_position('e',1)),
                                                      m_kingB(Position::create_position('e',8)){
//  Create the pieces of the chessboard
    piecesSet(boardData);
    std::cout << "---It's white who play---" << std::endl;
}
/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
/// @brief Instantiate the pieces of the chessboard
/// @param the board given in string format
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


 /*      PRINT
  * ----------------------------------------------------------*/
/// @brief Change board format into a vector of char
/// @details Each piece is represented by a char : r(rook), p(pawn),
/// h(knight), b(bishop), q(queen), k(king)
std::vector<char> ChessBoard::chessboardToChar() const{
    std::vector<char> print_board(m_lines*m_lines,' ');
    for (auto const & b : m_board){
        print_board[(b.first).getCoord()] = (b.second)->getType();
    }
    return print_board;
}

/// @brief Add decorator to the board
/// @param the board converted into a vector of char
/// @return a string containing the whole board
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

/*      MOVE
 * ----------------------------------------------------------*/
/// @brief Move a piece from a start position to a final position
/// @param start position
/// @param final position
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

    /*          check : the right color to play ?
    ***************************************************/
    if (p_piece->getColor() != m_color_active){
        std::cout << "Displacement is NOT VALID" << std::endl;
        return ;
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
    if(p_piece->isKing()) setKingPosition(pAfter, m_color_active);
    m_color_active = switch_color(m_color_active);
    if (m_color_active==ColorOfPieces::WHITE)std::cout << "---It's white who play---" << std::endl;
    if (m_color_active==ColorOfPieces::BLACK)std::cout << "---It's black who play---" << std::endl;

}


/// @brief Tell if the displacement from a start position to a final position is valid
/// @param start position
/// @param final position
/// @return a boolean to true is the displacement is valid, false otherwise
bool ChessBoard::moveIsValid(Position const & pBefore, Position const & pAfter) const{

    bool valid = true;

    /*          check : is a piece at initial position ?
    ***************************************************/
    if(m_board.find(pBefore) == m_board.end()){
        return false;
    }

    // take the piece to move
    std::shared_ptr<Piece> p_piece;
    p_piece = m_board.at(pBefore);
    // is there a piece at the final position?
    std::shared_ptr<Piece> p_piece_after;
    bool isPieceAfter = false;
    if (m_board.find(pAfter) != m_board.end()){
        isPieceAfter=true;
        p_piece_after = m_board.at(pAfter);
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


/// @brief Show the valid displacements of a piece from a start position
/// @param start position
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

/// @brief Trajectory from piece rules is changed to take into account of the pieces on the board
/// @param trajectory from piece rules
/// @param final position
/// @return a new trajectory
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

/*      CHESSMATE
 * ----------------------------------------------------------*/
/// @brief Check if a position can be attacked by the other color
/// @param position to check
/// @param color of that position
bool ChessBoard::isChess(char const & king) const {
    // 1 - it has to be a king 'k' ou 'K'
    if (tolower(king) != 'k') {
        assert("Chess is only valid on king !");
    }
    // 2 - retrieve king position
    Position kingPos = m_kingW;
    ColorOfPieces color_attacker = ColorOfPieces::BLACK;
    if (king == 'K') {
        kingPos = m_kingB;
        color_attacker = ColorOfPieces::WHITE;
    }
    // 3 - check if there king is at the right position
    if (m_board.find(kingPos) == m_board.end()) {
        assert("King not found at its position!");
    }
    // 4 - chess test
    return chessTest(kingPos, color_attacker);
}

/// @brief Check if a king is mate
/// @param pos position to check if it is threaten by pieces of color_attacker
/// @param color_attacker color of the pieces which attack the position pos
bool ChessBoard::chessTest(Position const & pos, ColorOfPieces color_attacker) const{
    bool valid{false};
    for (auto const & b : m_board){
        if (color_attacker!= (b.second)->getColor()){
            continue;
        }
        else if(b.first==pos){
            continue;
        }
        else{
            valid = moveIsValid(b.first,pos);
            std::cout << "check if move is valid" << valid<< std::endl;
            if(valid) break;
        }
    }
    return valid;
}

void ChessBoard::checkKing(char const & king) const {
    // 1 - it has to be a king 'k' ou 'K'
    if (tolower(king) != 'k') {
        assert("Chess is only valid on king !");
    }

    // 2 - retrieve king position
    Position kingPos{getKingPosition(king)};

    // 3 - check if there is a piece at that position
    if (m_board.find(kingPos) == m_board.end()) {
        assert("King not found at its position!");
    }

    // 4 - check if the piece found is a king
    std::shared_ptr<Piece> p_piece;
    p_piece = m_board.at(kingPos);
    if (!(p_piece->isKing())) {
        assert("The piece found at the position is not a king!");
    }
}


/// @brief Check if a king is mate
bool ChessBoard::isMate(char const & king) const {
    // proceed to checks
    checkKing(king);

    // get color of the attackers
    ColorOfPieces color_attacker{ColorOfPieces::BLACK};
    if (king == 'K') color_attacker = ColorOfPieces::WHITE;

    // get king position
    Position kingPos{getKingPosition(king)};

    // 4 - mate test
    return mateTest(kingPos, color_attacker);
}


/// @brief Check if a king is mate
bool ChessBoard::mateTest(Position const & pos, ColorOfPieces color_attacker) const{
    bool is_attacked{false};

//  retrieve king piece
    std::shared_ptr<Piece> p_piece;
    p_piece = m_board.at(pos);

    // check if mate
    trajectory pathVector;
    pathVector = p_piece->drawTraject(pos);
    // loop on paths
    for (path const & path1 : pathVector) {
        // loop on positions
        for (Position const &pos : path1) {
            if(moveIsValid(pos,pos)) {
                is_attacked = chessTest(pos, color_attacker);
                if (!is_attacked) return false;
            }
        }
    }
    return true;
}

/// @brief Check if a king is chessmate
/// @return boolean true if chessmate detected
bool ChessBoard::isChessMate() const{
    bool is_chessmateW{false};
    bool is_chessmateB{false};
//  white king
    is_chessmateW = isChess('k') && isMate('k');
//  black king
    is_chessmateB = isChess('K') && isMate('K');
    return ( is_chessmateW || is_chessmateB);
}

/*      PROMOTION
 * ----------------------------------------------------------*/



/* ----------------------------------------------------------
 *      SETTER/ GETTER
 * ----------------------------------------------------------*/

/// @brief Change the score of white or black
/// @param value of the piece eaten
/// @param color of the winner (the one whom the score is changed)
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

/// @brief Getter of score for the white
/// @return score of white
int ChessBoard::getScoreW() const{
    return m_scoreW;
}

/// @brief Getter of score for the black
/// @return score of black
int ChessBoard::getScoreB() const{
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

/// @brief Switch the active color
/// @param the color to be set active
ColorOfPieces ChessBoard::switch_color(ColorOfPieces color) const{
    switch (color) {
        case ColorOfPieces::WHITE:
            return ColorOfPieces::BLACK;
        case ColorOfPieces::BLACK:
            return ColorOfPieces::WHITE;
    }
}

/// @brief Setter : position of the king
/// @param position of the king
/// @param color of the king
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

Position ChessBoard::getKingPosition(char const & king)const{
    if (king=='k'){
        return m_kingW;
    }
    else if (king=='K'){
        return m_kingB;
    }
    else{
        assert("Cannot return position");
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