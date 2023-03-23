//
// Created by xllcr on 21/02/2023.
//

#include "ChessBoard.h"
#include <string>
#include <iterator>
#include <numeric>
#include <functional>
#include <memory>
#include <cassert>
#include <Cross.h>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "ChessMove.h"

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
                         m_kingB(Position::create_position('e',8)),
                         m_castlingW(false),
                         m_castlingB(false){
    //  Create the pieces of the chessboard
    piecesSet("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
    printActiveColor();
}

/// @brief Constructor from a string
/// @param string describing how the chessboard is filled (example : "rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")
///
ChessBoard::ChessBoard(std::string const & boardData):m_scoreW(0),
                                                      m_scoreB(0),
                                                      m_color_active(ColorOfPieces::WHITE),
                                                      m_kingW(Position::create_position('e',1)),
                                                      m_kingB(Position::create_position('e',8)),
                                                      m_castlingW(false),
                                                      m_castlingB(false){
//  Create the pieces of the chessboard
    piecesSet(boardData);
    printActiveColor();
}

/// @brief Constructor from a string
/// @param string describing how the chessboard is filled (example : "rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")
///
ChessBoard::ChessBoard(std::string const & boardData, char c):m_scoreW(0),
                                                      m_scoreB(0),
                                                      m_kingW(Position::create_position('e',1)),
                                                      m_kingB(Position::create_position('e',8)),
                                                      m_castlingW(false),
                                                      m_castlingB(false){

     m_color_active = getColorfromChar(c);

    //  Create the pieces of the chessboard
    piecesSet(boardData);
    printActiveColor();
}
/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/
/// @brief Instantiate the pieces of the chessboard
/// @param the board given in string format
void ChessBoard::piecesSet(std::string const & boardData){
    auto rank=1;
    auto i=-1;
    std::string abc{"abcdefgh"};
    std::string pieces{"rhbqkpxRHBQKPX"};
    for (auto const & C : boardData){
        ++i;
        if(std::isdigit(C)) continue;
        std::size_t found = pieces.find(C);
        if (found!=std::string::npos){
            if (rank>8) assert("Bad string initialization to set boardchess pieces. Too much characters");
            ColorOfPieces color=ColorOfPieces::WHITE;
            if (isupper(C)) color=ColorOfPieces::BLACK;
            Position pos=Position::create_position(abc[i],rank);
            createPiece(C, pos, color);
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

void ChessBoard::createPiece(char c, Position const & pos, ColorOfPieces color) {
    bool hasMoved = true;
    if (c!='q' || c!='r' || c!='b' || c!='h' || c!='p' || c!='k'|| c!='x'){
        assert("Bad char to create piece");
    }
    std::shared_ptr<Piece> p_piece ;
    if(tolower(c)=='q') p_piece = std::make_shared<Queen> (Queen(color));
    if(tolower(c)=='r') p_piece = std::make_shared<Rook> (Rook(color));
    if(tolower(c)=='b') p_piece = std::make_shared<Bishop> (Bishop(color));
    if(tolower(c)=='h') p_piece = std::make_shared<Knight> (Knight(color));
    if(tolower(c)=='p') p_piece = std::make_shared<Pawn> (Pawn(color));
    if(tolower(c)=='x') p_piece = std::make_shared<Cross> (Cross(color));
    if(tolower(c)=='k') {
        p_piece = std::make_shared<King> (King(color));
        setKingPosition(pos, color);
    }
    if (p_piece->isInitialPosition(pos)) hasMoved = false;
    m_board.emplace(pos,std::make_tuple(p_piece, hasMoved));
}

 /*      PRINT
  * ----------------------------------------------------------*/
/// @brief Change board format into a vector of char
/// @details Each piece is represented by a char : r(rook), p(pawn),
/// h(knight), b(bishop), q(queen), k(king)
std::vector<char> ChessBoard::chessboardToChar() const{
    std::vector<char> print_board(m_lines*m_lines,' ');
    for (auto const & b : m_board){
        auto&[p_piece,hasMoved] = b.second;
        print_board[(b.first).getCoord()] = p_piece->getType();
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
bool ChessBoard::movePiece(Position const & pBefore, Position const & pAfter, bool move_active){

    // piece rules
    bool rules_valid    = isMoveValid(pBefore,pAfter);

    // castling
    bool castling_valid = isCastling(pBefore, pAfter);
    if (!rules_valid && !castling_valid){
//        std::cout << "Displacement is NOT VALID" << std::endl;
        return false;
    }

    // take the piece to move
    auto[p_piece,hasMoved] = m_board.at(pBefore);
    // check : the right color to play ?
    if (p_piece->getColor() != m_color_active){
        return false;
    }

    auto save_score=0;
    if (move_active) {
        if (rules_valid) {
            // is there a piece at the final position?
            bool isPieceAfter = m_board.find(pAfter) != m_board.end();

            if (isPieceAfter) {                                             // there is a piece at final position
                auto&[p_piece_after, hasMoved] = m_board.at(pAfter);
                save_score = p_piece_after->getValue();
                m_board.erase(pAfter);
            }
            m_board.erase(pBefore);
            m_board.emplace(pAfter, std::make_tuple(p_piece, true));
        } else if (castling_valid) {
            // king move
            m_board.erase(pBefore);
            m_board.emplace(pAfter, std::make_tuple(p_piece, true));
            // rook move
            int line = pBefore.getY();
            Position posShort = Position::create_position('g', line);
            Position posLong = Position::create_position('c', line);
            Position pBeforeR = Position::create_position('a', 1);
            Position pAfterR = Position::create_position('a', 1);
            if (pAfter == posShort) {
                pBeforeR = Position::create_position('h', line);
                pAfterR = Position::create_position('f', line);
                auto[p_pieceR, hasMoved] = m_board.at(pBeforeR);
                m_board.erase(pBeforeR);
                m_board.emplace(pAfterR, std::make_tuple(p_pieceR, true));
            } else {
                pBeforeR = Position::create_position('a', line);
                pAfterR = Position::create_position('d', line);
                auto[p_pieceR, hasMoved] = m_board.at(pBeforeR);
                m_board.erase(pBeforeR);
                m_board.emplace(pAfterR, std::make_tuple(p_pieceR, true));
            }
        }
    }

    // side effects
    if (rules_valid) {
        setScore(save_score, p_piece->getColor());
    } else if (castling_valid) {
        setCastling(true, p_piece->getColor());
    }
    if(p_piece->isKing()) setKingPosition(pAfter, p_piece->getColor());
    m_color_active = switch_color(m_color_active);
    pawnPromotion(pAfter);
    return true;
//    if (m_color_active==ColorOfPieces::WHITE)std::cout << "---It's white who play---" << std::endl;
//    if (m_color_active==ColorOfPieces::BLACK)std::cout << "---It's black who play---" << std::endl;
}

// @brief Find all the potential moves of the board for pieces of color "color"
// @param color : the color to play
// @return a vector of moves
std::tuple<std::vector<ChessMove>,int> ChessBoard::potentialMoves(ColorOfPieces color){
    std::vector<ChessMove> potMoves;
    std::vector<Position> pos_attacked = planAttacked(color);
    trajectory traject;
    for (auto const & b : m_board){
        auto&[p_piece,hasMoved] = b.second;
        if (color!= p_piece->getColor()){
            continue;
        }
        // draw potentials of the pieces attacker
        traject = drawPotentials(b.first, false);
        if (!traject.empty()) {
            for (path const &path1 : traject) {
                for (Position const &pos : path1) {
                    if(pos!=b.first) potMoves.emplace_back(ChessMove(b.first, pos, p_piece->getType()));
                }
            }
        }
    }
    int score= compute_score(color);
    return std::make_tuple(potMoves, score);
}


///// @brief Tell if the displacement from a start position to a final position is valid
///// @param start position
///// @param final position
///// @return a boolean to true is the displacement is valid, false otherwise
bool ChessBoard::isMoveValid(Position const & pBefore, Position const & pAfter) const{

    if (pBefore == pAfter) return false;
    trajectory traject = drawPotentials(pBefore, false);

    if (traject.empty()) {
        return false;
    }
    else{
        // find pAfter in traject
        // loop on paths
        for (path const & path1 : traject) {
            // loop on positions
            for (Position const &pos : path1) {
//                std::cout << "test de la pos" << pAfter << std::endl;
                if (pos == pAfter){return true;}
            }
        }
    }
    return false;
}


/// @brief Show the valid displacements of a piece from a start position
/// @param start position
void ChessBoard::moveHelp(Position const & pBefore) {
    if(m_board.find(pBefore) == m_board.end()){
        std::cout << "No piece found at that position";
        return;
    }

    auto&[p_piece,hasMoved] = m_board.at(pBefore);
    trajectory pathVector = drawPotentials(pBefore);
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

trajectory ChessBoard::drawPotentials(Position const & pBefore, bool fromMate) const{
    trajectory new_traject, traject;
    path new_path;
    trajectory pathVector;
    trajectory new_traject1;
    path new_path1;

    // check : is a piece at initial position ?
    if(m_board.find(pBefore) == m_board.end()){
        return new_traject;
    }
    // take the piece to move
    auto&[p_piece,hasMovedB] = m_board.at(pBefore);
    ColorOfPieces color = p_piece->getColor();
    bool isPawn = tolower(p_piece->getType()) == 'p';
    bool isKing = tolower(p_piece->getType()) == 'k';
    bool isX = tolower(p_piece->getType()) == 'x';
    if (isX) return new_traject;

    traject = p_piece->drawTraject(pBefore,hasMovedB);

    if ((isKing && fromMate)|| !isKing) {
//        std::cout << "je passe ici qd je suis pas un roi" << std::endl;
        // loop on paths
        for (path const &path1 : traject) {
            new_path.clear();
            // loop on positions
            for (Position const &pos : path1) {
                bool onlyDiagonal = pos.getX() != pBefore.getX();
                bool isPieceAfter = m_board.find(pos) != m_board.end();
                if (!isPieceAfter) {
                    // position not found : position is free
                    if (isPawn) {
                        if (fromMate && onlyDiagonal) {
//                            std::cout << "pawn at2 " << p_piece->getType()<<pBefore <<"from mate can take that place : "<< pos << std::endl;
                            new_path.push_back(pos);
                        }  // only diagonal
                        else if (!fromMate && !onlyDiagonal) { new_path.push_back(pos); }  // only vertical
                    } else {
                        new_path.push_back(pos);
                    }
                } else {
                    // position found : position is occupied
                    auto&[p_piece_after, hasMovedA] = m_board.at(pos);
                    bool isSameColor = color == p_piece_after->getColor();
                    bool isTakenX = tolower(p_piece_after->getType()) == 'x';
                    bool onlyDiagonal = pos.getX() != pBefore.getX();
                    // case 1
                    if (isTakenX) { break; }  // 'x' cannot be taken
                    // case 2
                    if (fromMate && isSameColor) { // can take your own color...
                        if (isPawn && onlyDiagonal) {
//                            std::cout << "pawn at3 " << p_piece->getType()<<pBefore <<"from mate can take that place : "<< pos << std::endl;
                            new_path.push_back(pos); }  // only diagonal
                        else { new_path.push_back(pos); }
                        break;
                    }
                    // case 3
                    if (!fromMate && !isSameColor) { // general case : can take the opposite color
                        if (isPawn && onlyDiagonal) {
//                            std::cout << "pawn at " << p_piece->getType()<<pBefore <<"not mate can take that place : "<< pos << std::endl;
                            new_path.push_back(pos); }  // only diagonal
                        else { new_path.push_back(pos); }
                        break;
                    }
                    // case 4 : king is attacked
                    if((fromMate && (pos==getKingPosition('k') ||pos==getKingPosition('K')))){
                        new_path.push_back(pos);
                    }
                }
            }
            if(!std::empty(new_path)) new_traject.insert(new_path);
        }
        return new_traject;
    }
    else {
//        std::cout << "je suis un roi - verif du mate"<<p_piece->getType()<< pBefore << std::endl;
//        std::cout << "PREPARATION DU PLAN D'ATTAQUE" << std::endl;
        std::vector<Position> pos_attacked = planAttacked(switch_color(color), true);
//        for (auto const & truc : pos_attacked){std::cout <<"pos attaquees : " << truc<<std::endl;}
//        std::cout << "FIN DU PLAN D'ATTAQUE" << std::endl;
        // loop on paths
        for (path const &path2 : traject) {
            new_path1.clear();
            // loop on positions
            for (Position const &pos : path2) {   // all potential positions of the king
                // check if it's in the attack plan : if not add pos
                bool isPieceAfter = m_board.find(pos) != m_board.end();
                bool pieceX = false;
                ColorOfPieces colorAfter = switch_color(p_piece->getColor());
                if (isPieceAfter){
                    auto&[p_piece_after, hasMovedA] = m_board.at(pos);
                    pieceX=tolower(p_piece_after->getType())=='x';
                    colorAfter = p_piece_after->getColor();
                }
                if (!pieceX && !isAttacked(pos, pos_attacked) && colorAfter!=p_piece->getColor()){
//                    std::cout << "pos pas attaquee elle est ok!"<< pos << std::endl;
                    new_path1.push_back(pos);
                }
            }
            if(!std::empty(new_path1)) new_traject1.insert(new_path1);
        }
        // check if chess (king attacked), if not: pBefore is added to the traject
        if (!isAttacked(pBefore, pos_attacked)){
//            std::cout << "le roi nest pas attaque" <<std::endl;
            new_path1.clear();
            new_path1.push_back(pBefore);
            new_traject1.insert(new_path1);
        }
    }
    return new_traject1;
}

/*      CASTLING
 * ----------------------------------------------------------*/
/// @brief Check if there is castling
/// @param initial position
/// @param final position
bool ChessBoard::isCastling(Position const & pBeforeK, Position const & pAfterK) const {
/*    Neither the king nor the rook has previously moved.
      There are no pieces between the king and the rook.
      The king is not currently in check.
      The king does not pass through or finish on a square that is attacked by an enemy piece.
*/

    // check : is a piece at initial position ?
    if(m_board.find(pBeforeK) == m_board.end()) return false;

    auto&[p_pieceK,hasMovedK] = m_board.at(pBeforeK);
    // is there a king at initial position
    if (!(p_pieceK->isKing())) return false;
    // castling only once
    if (getCastling(p_pieceK->getColor())) return false;
    // short castling/ long castling
    int line = pBeforeK.getY();
    Position posShort = Position::create_position('g',line);
    Position posLong  = Position::create_position('c',line);
    Position pBeforeR = Position::create_position('a',1);
    Position pAfterR  = Position::create_position('a',1);
    Position pEmpty   = Position::create_position('b',line);
    // pAfter is position of small/long castling
    if (pAfterK==posShort) {
        pBeforeR = Position::create_position('h', line);
        pAfterR = Position::create_position('f', line);
    }
    else if (pAfterK==posLong){
        pBeforeR = Position::create_position('a',line);
        pAfterR = Position::create_position('d',line);
    }
    else{
        return false;
    }
    // check if there is a rook
    if (m_board.find(pBeforeR) == m_board.end()) return false;
    auto[p_pieceR,hasMovedR] = m_board.at(pBeforeR);
    if (!(p_pieceR->isRook())) return false;
    if (p_pieceR->getColor() != p_pieceK->getColor()) return false;

    // never moved
    if (hasMovedK || hasMovedR) return false;

    // no piece between the king and the rook
    if (m_board.find(pAfterR) != m_board.end()) return false;
    if (m_board.find(pAfterK) != m_board.end()) return false;
    if (pAfterK==posLong){
        if (m_board.find(pEmpty) != m_board.end()) return false;
    }

    // king cannot be in check
    if (isChessMate(ChessMateChoice::CHESS, p_pieceK->getType())) return false;

    // the empty positions cannot be attacked
    std::vector<Position> pos_attacked = planAttacked(switch_color(p_pieceK->getColor()));
    if(isAttacked(pAfterK, pos_attacked)) return false;
    if(isAttacked(pAfterR, pos_attacked)) return false;
    if (pAfterK==posLong && isAttacked(pEmpty, pos_attacked)) return false;
    return true;
}

/*      CHESSMATE
 * ----------------------------------------------------------*/
/// @brief Check if a king is chessmate
/// @return boolean true if chessmate detected
bool ChessBoard::isChessMate(ChessMateChoice const & choice, char const & king) const{
    return (checkChessMate(king) == choice);
}

/// @brief Check if a position can be attacked by the other color
/// @param position to check
/// @param color of that position
ChessMateChoice ChessBoard::checkChessMate(char const & king) const {
    // checks on king
    if (!checkKing(king)) { return ChessMateChoice::NOCHESSMATE;}

    // get king position
    Position kingPos{getKingPosition(king)};

    // chess test
    trajectory traject = drawPotentials(kingPos);
    if(traject.empty()) {
        return ChessMateChoice::CHESSMATE;
    }
    else{ // find its position in the traject
        bool kingFound = false;
        unsigned int trajectSize=0;
        for (path const &path1 : traject) {
            trajectSize +=path1.size();
            if (std::find(path1.begin(), path1.end(), kingPos) != path1.end()) {
                kingFound = true;
            }
        }
        for (path const &path1 : traject) {
            for (Position const &pos : path1) {
                if (pos == kingPos){kingFound = true;}
            }
        }
        if (!kingFound) {
            return ChessMateChoice::CHESS;}
        else {
            if (trajectSize==1) return ChessMateChoice::MATE;
        }
    }
    return ChessMateChoice::NOCHESSMATE;
}

/// @brief Check if a king is mate
/// @param pos position to check if it is threaten by pieces of color_attacker
/// @param color_attacker color of the pieces which attack the position pos
bool ChessBoard::isAttacked(Position const & pos, std::vector<Position> const & pos_attacked) const{
    if ( std::find(pos_attacked.begin(), pos_attacked.end(), pos) == pos_attacked.end() ){
        return false;
    }
    return true;
}

/// @brief Check if a king is mate
/// @param pos position to check if it is threaten by pieces of color_attacker
/// @param color_attacker color of the pieces which attack the position pos
std::vector<Position> ChessBoard::planAttacked(ColorOfPieces color_attacker, bool fromMate) const{
    std::vector<Position> pos_attacked;
    trajectory traject;
    for (auto const & b : m_board){
        auto&[p_piece,hasMoved] = b.second;
        if (color_attacker!= p_piece->getColor()){
            continue;
        }
        // draw potentials of the pieces attacker
        traject = drawPotentials(b.first, fromMate);
        if (!traject.empty()) {
            for (path const &path1 : traject) {
                for (Position const &pos : path1) {
                    pos_attacked.emplace_back(pos);
                }
            }
        }
    }
    return pos_attacked;
}

bool ChessBoard::checkKing(char const & king) const {
    // 1 - it has to be a king 'k' ou 'K'
    if (tolower(king) != 'k') {
        //assert("Chess is only valid on king !");
        return false;
    }

    // 2 - retrieve king position
    Position kingPos{getKingPosition(king)};

    // 3 - check if there is a piece at that position
    if (m_board.find(kingPos) == m_board.end()) {
        //assert("King not found at its position!");
        return false;
    }

    // 4 - check if the piece found is a king
    auto&[p_piece,hasMoved] =m_board.at(kingPos);
    if (!(p_piece->isKing())) {
        //assert("The piece found at the position is not a king!");
        return false;
    }
    return true;
}

/*      PROMOTION
 * ----------------------------------------------------------*/
void ChessBoard::pawnPromotion(Position const & pos){
    char promo;
    std::string pieces{"rhbqkpRHBQKP"};

    // check if the piece is a pawn to promote
    auto&[p_piece,hasMoved] =m_board.at(pos);
    if(!p_piece->isPromoted(pos)) return;

    // ask user
    std::cout << "Pawn promotion, choose between r, h, b and q" << std::endl;
    while(!( std::cin >> promo) || pieces.find(promo)==std::string::npos ){
        std::cout << "Please, choose between r, h, b and q" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    promotion(promo, pos);

}

void ChessBoard::promotion(char const &promo, Position const & pos){
    auto&[p_piece,hasMoved] =m_board.at(pos);
    ColorOfPieces color=p_piece->getColor();
    // erase pos+pawn of the board
    m_board.erase(pos);
    // create the new piece & add the piece to the board
    createPiece(tolower(promo),pos,color);
}

int ChessBoard::compute_score(ColorOfPieces color){
    auto score{0};
    auto coef{1};
    auto value{0};
    auto letter{false};
    auto number{false};
    std::string center_letters{"cefg"};
    // compute score = number of pieces on the board of the current color
    for (auto const & b : m_board) {
        auto&[p_piece, hasMoved] = b.second;
        if (color == p_piece->getColor()) {
            value = p_piece->getValue();
            if (center_letters.find(b.first.getX())!=std::string::npos) letter = true;
            if (b.first.getY()>=3 && b.first.getY()<=6) number = true;
            if(letter || number) coef = 2;
            if(letter && number) coef = 3;
        }
        score +=coef*value;
    }
return score;
}


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

void ChessBoard::printScores(){
    std::cout << "The score of WHITE is : " << m_scoreW << std::endl;
    std::cout << "The score of BLACK is : " << m_scoreB << std::endl;
}

void ChessBoard::printActiveColor()const{
    switch (m_color_active) {
        case ColorOfPieces::WHITE:
            std::cout << "*** WHITE start playing ***" << std::endl;
            break;
        case ColorOfPieces::BLACK:
            std::cout << "*** BLACK start playing ***" << std::endl;
            break;
    }
}

/// @brief Take boolean castling depending on color
/// @param the color to be set active
bool ChessBoard::getCastling(ColorOfPieces color)const{
    switch (color) {
        case ColorOfPieces::WHITE:
            return m_castlingW;
            break;
        case ColorOfPieces::BLACK:
            return m_castlingB;
            break;
    }
}

void ChessBoard::setCastling(bool castling, ColorOfPieces color){
    switch (color) {
        case ColorOfPieces::WHITE:
            m_castlingW = castling;
            break;
        case ColorOfPieces::BLACK:
            m_castlingB = castling;
            break;
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

char ChessBoard::getPieceType(Position const & pos)const{
    auto[p_piece,hasMoved] =m_board.at(pos);
    return p_piece->getType();
}

ColorOfPieces ChessBoard::getColorfromChar(char c)const{
    ColorOfPieces color_active;
    if (tolower(c)=='w'){
        return ColorOfPieces::WHITE;
    }
    else if (tolower(c)=='b'){
        return ColorOfPieces::BLACK;
    }
    else{
        assert("Bad starting color : choose between 'w' (white) and 'b' (black)");
    }
}

ColorOfPieces ChessBoard::getColorActive()const{
    return m_color_active;
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

/// @brief Switch the active color
/// @param the color to be set active
ColorOfPieces switch_color(ColorOfPieces color){
    switch (color) {
        case ColorOfPieces::WHITE:
            return ColorOfPieces::BLACK;
            break;
        case ColorOfPieces::BLACK:
            return ColorOfPieces::WHITE;
            break;
    }
}

/// @brief Switch the active color
/// @param the color to be set active
ColorOfPieces switch_color(char c){
    ColorOfPieces color = ColorOfPieces::WHITE;
    if (isupper(c)) color = ColorOfPieces::BLACK;
    return switch_color(color);
}

std::ostream& operator<<(std::ostream& os , ColorOfPieces color){
    switch (color) {
        case ColorOfPieces::WHITE:
            return os << "white";
            break;
        case ColorOfPieces::BLACK:
            return os << "black";
            break;
    }
}


ChessBoard play(ChessMove move, ChessBoard board){
    board.movePiece(move.start_pos,move.end_pos);
    return board;
}


