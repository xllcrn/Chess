//
// Created by xllcr on 21/02/2023.
//

#include <string>
#include <iterator>
#include <numeric>
#include <functional>
#include <cassert>
#include "ChessMove.h"
#include "ChessModel.h"

/* ----------------------------------------------------------
 *      STATIC METHODS
 * ----------------------------------------------------------*/


/* ----------------------------------------------------------
 *      CONSTRUCTORS
 * ----------------------------------------------------------*/





///// @brief Default constructor
/////
//ChessBoard::ChessBoard(){
//    //  Create the pieces of the chessboard
//    piecesSet("rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR");
//    printActiveColor();
//}
//
///// @brief Constructor from a string
///// @param string describing how the chessboard is filled (example : "rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")
/////
//ChessBoard::ChessBoard(std::string const & boardData){
////  Create the pieces of the chessboard
//    piecesSet(boardData);
//    printActiveColor();
//}
//
///// @brief Constructor from a string
///// @param string describing how the chessboard is filled (example : "rhbqkbhr/pppppppp/8/8/8/8/PPPPPPPP/RHBQKBHR")
/////
//ChessBoard::ChessBoard(std::string const & boardData, char c){
//
//     m_color_active = getColorfromChar(c);
//
//    //  Create the pieces of the chessboard
//    piecesSet(boardData);
//    printActiveColor();
//}


/* ----------------------------------------------------------
 *      MEMBER METHODS
 * ----------------------------------------------------------*/

/*      MOVE
 * ----------------------------------------------------------*/
/// @brief Move a piece from a start position to a final position
/// @param start position
/// @param final position
//bool ChessModel::movePiece(Position const & pBefore, Position const & pAfter, bool move_active){
//
//    // piece rules
//    bool rules_valid    = isMoveValid(pBefore,pAfter);
//
//    // castling
//    bool castling_valid = isCastling(pBefore, pAfter);
//    if (!rules_valid && !castling_valid){
////        std::cout << "Displacement is NOT VALID" << std::endl;
//        return false;
//    }
//
//    // take the piece to move
//    auto p_piece = m_board->getPiece(pBefore);
//    // check : the right color to play ?
//    if (p_piece->getColor() != m_color_active){
//        return false;
//    }
//
//    auto save_score=0;
//    if (move_active) {
//        if (rules_valid) {
//            // is there a piece at the final position?
//            bool isPieceAfter = m_board->isPiece(pAfter);
//
//            if (isPieceAfter) {                                             // there is a piece at final position
//                auto p_piece_after = m_board->getPiece(pAfter);
//                save_score = p_piece_after->getValue();
//                m_board->deletePiece(pAfter);
//            }
//            m_board->movePiece(pBefore,pAfter);
//        } else if (castling_valid) {
//            // king move
//            m_board->movePiece(pBefore,pAfter);
//            // rook move
//            int line = pBefore.getY();
//            Position posShort = Position::create('g', line);
//            Position posLong = Position::create('c', line);
//            Position pBeforeR = Position::create('a', 1);
//            Position pAfterR = Position::create('a', 1);
//            if (pAfter == posShort) {
//                pBeforeR = Position::create('h', line);
//                pAfterR = Position::create('f', line);
//                m_board->movePiece(pBeforeR,pAfterR);
//            } else {
//                pBeforeR = Position::create('a', line);
//                pAfterR = Position::create('d', line);
//                m_board->movePiece(pBeforeR,pAfterR);
//            }
//        }
//    }
//
//    // side effects
//    if (rules_valid) {
//        setScore(save_score, p_piece->getColor());
//    } else if (castling_valid) {
//        setCastling(true, p_piece->getColor());
//    }
//    if(p_piece->isKing()) setKingPosition(pAfter, p_piece->getColor());
//    m_color_active = switch_color(m_color_active);
//    pawnPromotion(pAfter);
//    p_piece->setMoved();
//    return true;
////    if (m_color_active==Color::WHITE)std::cout << "---It's white who play---" << std::endl;
////    if (m_color_active==Color::BLACK)std::cout << "---It's black who play---" << std::endl;
//}

// @brief Find all the potential moves of the board for pieces of color "color"
// @param color : the color to play
// @return a vector of moves
//std::tuple<std::vector<ChessMove>,int> ChessModel::potentialMoves(Color color){
//    std::vector<ChessMove> potMoves;
//    std::vector<Position> pos_attacked = planAttacked(color);
//    trajectory traject;
//    for (auto const & b : (*m_board)){
//        auto&[p_piece,hasMoved] = b.second;
//        if (color!= p_piece->getColor()){
//            continue;
//        }
//        // draw potentials of the pieces attacker
//        traject = drawPotentials(b.first, false);
//        if (!traject.empty()) {
//            for (path const &path1 : traject) {
//                for (Position const &pos : path1) {
//                    if(pos!=b.first) potMoves.emplace_back(ChessMove(b.first, pos, p_piece->getType()));
//                }
//            }
//        }
//    }
//    int score= compute_score(color);
//    return std::make_tuple(potMoves, score);
//}
//

///// @brief Tell if the displacement from a start position to a final position is valid
///// @param start position
///// @param final position
///// @return a boolean to true is the displacement is valid, false otherwise
//bool ChessModel::isMoveValid(Position const & pBefore, Position const & pAfter) const{
//
//    if (pBefore == pAfter) return false;
//    trajectory traject = drawPotentials(pBefore, false);
//
//    if (traject.empty()) {
//        return false;
//    }
//    else{
//        // find pAfter in traject
//        // loop on paths
//        for (path const & path1 : traject) {
//            // loop on positions
//            for (Position const &pos : path1) {
////                std::cout << "test de la pos" << pAfter << std::endl;
//                if (pos == pAfter){return true;}
//            }
//        }
//    }
//    return false;
//}


/// @brief Show the valid displacements of a piece from a start position
/// @param start position
//void ChessModel::moveHelp(Position const & pBefore) {
//    if(m_board.find(pBefore) == m_board.end()){
//        std::cout << "No piece found at that position";
//        return;
//    }
//
//    auto&[p_piece,hasMoved] = m_board.at(pBefore);
//    trajectory pathVector = drawPotentials(pBefore);
//    std::cout << "All possible moves for the piece" << std::endl;
//    std::cout << *p_piece << std::endl;
//    for (auto paths : pathVector) {
//        for (auto pos : paths) {
//            std::cout << pos;
//        }
//    }
//
////    std::vector<char> print_board{chessboardToChar()};
//////  if trajectory for help
////    if(!pathVector.empty()) {
////        for (auto paths : pathVector) {
////            for (auto pos : paths) {
////                print_board[pos.getCoord()] = 'x';
////            }
////        }
////    }
////    std::cout << boardToString(print_board);
//}
//
//trajectory ChessModel::drawPotentials(Position const & pBefore, bool fromMate) const{
//    trajectory new_traject, traject;
//    path new_path;
//    trajectory pathVector;
//    trajectory new_traject1;
//    path new_path1;
//
//    // check : is a piece at initial position ?
//    if(m_board->isPiece(pBefore)){
//        return new_traject;
//    }
//    // take the piece to move
//    auto p_piece = m_board->getPiece(pBefore);
//    Color color = p_piece->getColor();
//    bool isPawn = tolower(p_piece->getType()) == 'p';
//    bool isKing = tolower(p_piece->getType()) == 'k';
//    bool isX = tolower(p_piece->getType()) == 'x';
//    if (isX) return new_traject;
//
//    traject = p_piece->drawTraject(pBefore);
//
//    if ((isKing && fromMate)|| !isKing) {
////        std::cout << "je passe ici qd je suis pas un roi" << std::endl;
//        // loop on paths
//        for (path const &path1 : traject) {
//            new_path.clear();
//            // loop on positions
//            for (Position const &pos : path1) {
//                bool onlyDiagonal = pos.getX() != pBefore.getX();
//                bool isPieceAfter = m_board.find(pos) != m_board.end();
//                if (!isPieceAfter) {
//                    // position not found : position is free
//                    if (isPawn) {
//                        if (fromMate && onlyDiagonal) {
////                            std::cout << "pawn at2 " << p_piece->getType()<<pBefore <<"from mate can take that place : "<< pos << std::endl;
//                            new_path.push_back(pos);
//                        }  // only diagonal
//                        else if (!fromMate && !onlyDiagonal) { new_path.push_back(pos); }  // only vertical
//                    } else {
//                        new_path.push_back(pos);
//                    }
//                } else {
//                    // position found : position is occupied
//                    auto&[p_piece_after, hasMovedA] = m_board.at(pos);
//                    bool isSameColor = color == p_piece_after->getColor();
//                    bool isTakenX = tolower(p_piece_after->getType()) == 'x';
//                    bool onlyDiagonal = pos.getX() != pBefore.getX();
//                    // case 1
//                    if (isTakenX) { break; }  // 'x' cannot be taken
//                    // case 2
//                    if (fromMate && isSameColor) { // can take your own color...
//                        if (isPawn && onlyDiagonal) {
////                            std::cout << "pawn at3 " << p_piece->getType()<<pBefore <<"from mate can take that place : "<< pos << std::endl;
//                            new_path.push_back(pos); }  // only diagonal
//                        else { new_path.push_back(pos); }
//                        break;
//                    }
//                    // case 3
//                    if (!fromMate && !isSameColor) { // general case : can take the opposite color
//                        if (isPawn && onlyDiagonal) {
////                            std::cout << "pawn at " << p_piece->getType()<<pBefore <<"not mate can take that place : "<< pos << std::endl;
//                            new_path.push_back(pos); }  // only diagonal
//                        else { new_path.push_back(pos); }
//                        break;
//                    }
//                    // case 4 : king is attacked
//                    if((fromMate && (pos==getKingPosition('k') ||pos==getKingPosition('K')))){
//                        new_path.push_back(pos);
//                    }
//                }
//            }
//            if(!std::empty(new_path)) new_traject.insert(new_path);
//        }
//        return new_traject;
//    }
//    else {
////        std::cout << "je suis un roi - verif du mate"<<p_piece->getType()<< pBefore << std::endl;
////        std::cout << "PREPARATION DU PLAN D'ATTAQUE" << std::endl;
//        std::vector<Position> pos_attacked = planAttacked(switch_color(color), true);
////        for (auto const & truc : pos_attacked){std::cout <<"pos attaquees : " << truc<<std::endl;}
////        std::cout << "FIN DU PLAN D'ATTAQUE" << std::endl;
//        // loop on paths
//        for (path const &path2 : traject) {
//            new_path1.clear();
//            // loop on positions
//            for (Position const &pos : path2) {   // all potential positions of the king
//                // check if it's in the attack plan : if not add pos
//                bool isPieceAfter = m_board.find(pos) != m_board.end();
//                bool pieceX = false;
//                Color colorAfter = switch_color(p_piece->getColor());
//                if (isPieceAfter){
//                    auto&[p_piece_after, hasMovedA] = m_board.at(pos);
//                    pieceX=tolower(p_piece_after->getType())=='x';
//                    colorAfter = p_piece_after->getColor();
//                }
//                if (!pieceX && !isAttacked(pos, pos_attacked) && colorAfter!=p_piece->getColor()){
////                    std::cout << "pos pas attaquee elle est ok!"<< pos << std::endl;
//                    new_path1.push_back(pos);
//                }
//            }
//            if(!std::empty(new_path1)) new_traject1.insert(new_path1);
//        }
//        // check if chess (king attacked), if not: pBefore is added to the traject
//        if (!isAttacked(pBefore, pos_attacked)){
////            std::cout << "le roi nest pas attaque" <<std::endl;
//            new_path1.clear();
//            new_path1.push_back(pBefore);
//            new_traject1.insert(new_path1);
//        }
//    }
//    return new_traject1;
//}

/*      CASTLING
 * ----------------------------------------------------------*/
/// @brief Check if there is castling
/// @param initial position
/// @param final position
//bool ChessModel::isCastling(Position const & pBeforeK, Position const & pAfterK) const {
///*    Neither the king nor the rook has previously moved.
//      There are no pieces between the king and the rook.
//      The king is not currently in check.
//      The king does not pass through or finish on a square that is attacked by an enemy piece.
//*/
//
//    // check : is a piece at initial position ?
//    if(m_board.find(pBeforeK) == m_board.end()) return false;
//
//    auto&[p_pieceK,hasMovedK] = m_board.at(pBeforeK);
//    // is there a king at initial position
//    if (!(p_pieceK->isKing())) return false;
//    // castling only once
//    if (getCastling(p_pieceK->getColor())) return false;
//    // short castling/ long castling
//    int line = pBeforeK.getY();
//    Position posShort = Position::create('g',line);
//    Position posLong  = Position::create('c',line);
//    Position pBeforeR = Position::create('a',1);
//    Position pAfterR  = Position::create('a',1);
//    Position pEmpty   = Position::create('b',line);
//    // pAfter is position of small/long castling
//    if (pAfterK==posShort) {
//        pBeforeR = Position::create('h', line);
//        pAfterR = Position::create('f', line);
//    }
//    else if (pAfterK==posLong){
//        pBeforeR = Position::create('a',line);
//        pAfterR = Position::create('d',line);
//    }
//    else{
//        return false;
//    }
//    // check if there is a rook
//    if (m_board.find(pBeforeR) == m_board.end()) return false;
//    auto[p_pieceR,hasMovedR] = m_board.at(pBeforeR);
//    if (!(p_pieceR->isRook())) return false;
//    if (p_pieceR->getColor() != p_pieceK->getColor()) return false;
//
//    // never moved
//    if (hasMovedK || hasMovedR) return false;
//
//    // no piece between the king and the rook
//    if (m_board.find(pAfterR) != m_board.end()) return false;
//    if (m_board.find(pAfterK) != m_board.end()) return false;
//    if (pAfterK==posLong){
//        if (m_board.find(pEmpty) != m_board.end()) return false;
//    }
//
//    // king cannot be in check
//    if (isChessMate(ChessMateChoice::CHESS, p_pieceK->getType())) return false;
//
//    // the empty positions cannot be attacked
//    std::vector<Position> pos_attacked = planAttacked(switch_color(p_pieceK->getColor()));
//    if(isAttacked(pAfterK, pos_attacked)) return false;
//    if(isAttacked(pAfterR, pos_attacked)) return false;
//    if (pAfterK==posLong && isAttacked(pEmpty, pos_attacked)) return false;
//    return true;
//}

/*      CHESSMATE
 * ----------------------------------------------------------*/
///// @brief Check if a king is chessmate
///// @return boolean true if chessmate detected
//bool ChessModel::isChessMate(ChessMateChoice const & choice, char const & king) const{
//    return (checkChessMate(king) == choice);
//}
//
///// @brief Check if a position can be attacked by the other color
///// @param position to check
///// @param color of that position
//ChessMateChoice ChessModel::checkChessMate(char const & king) const {
//    // checks on king
//    if (!checkKing(king)) { return ChessMateChoice::NOCHESSMATE;}
//
//    // get king position
//    Position kingPos{getKingPosition(king)};
//
//    // chess test
//    trajectory traject = drawPotentials(kingPos);
//    if(traject.empty()) {
//        return ChessMateChoice::CHESSMATE;
//    }
//    else{ // find its position in the traject
//        bool kingFound = false;
//        unsigned int trajectSize=0;
//        for (path const &path1 : traject) {
//            trajectSize +=path1.size();
//            if (std::find(path1.begin(), path1.end(), kingPos) != path1.end()) {
//                kingFound = true;
//            }
//        }
//        for (path const &path1 : traject) {
//            for (Position const &pos : path1) {
//                if (pos == kingPos){kingFound = true;}
//            }
//        }
//        if (!kingFound) {
//            return ChessMateChoice::CHESS;}
//        else {
//            if (trajectSize==1) return ChessMateChoice::MATE;
//        }
//    }
//    return ChessMateChoice::NOCHESSMATE;
//}
//
///// @brief Check if a king is mate
///// @param pos position to check if it is threaten by pieces of color_attacker
///// @param color_attacker color of the pieces which attack the position pos
//bool ChessModel::isAttacked(Position const & pos, std::vector<Position> const & pos_attacked) const{
//    if ( std::find(pos_attacked.begin(), pos_attacked.end(), pos) == pos_attacked.end() ){
//        return false;
//    }
//    return true;
//}
//
///// @brief Check if a king is mate
///// @param pos position to check if it is threaten by pieces of color_attacker
///// @param color_attacker color of the pieces which attack the position pos
//std::vector<Position> ChessModel::planAttacked(Color color_attacker, bool fromMate) const{
//    std::vector<Position> pos_attacked;
//    trajectory traject;
//    for (auto const & b : m_board){
//        auto&[p_piece,hasMoved] = b.second;
//        if (color_attacker!= p_piece->getColor()){
//            continue;
//        }
//        // draw potentials of the pieces attacker
//        traject = drawPotentials(b.first, fromMate);
//        if (!traject.empty()) {
//            for (path const &path1 : traject) {
//                for (Position const &pos : path1) {
//                    pos_attacked.emplace_back(pos);
//                }
//            }
//        }
//    }
//    return pos_attacked;
//}
//
//bool ChessModel::checkKing(char const & king) const {
//    // 1 - it has to be a king 'k' ou 'K'
//    if (tolower(king) != 'k') {
//        //assert("Chess is only valid on king !");
//        return false;
//    }
//
//    // 2 - retrieve king position
//    Position kingPos{getKingPosition(king)};
//
//    // 3 - check if there is a piece at that position
//    if (m_board.find(kingPos) == m_board.end()) {
//        //assert("King not found at its position!");
//        return false;
//    }
//
//    // 4 - check if the piece found is a king
//    auto&[p_piece,hasMoved] =m_board.at(kingPos);
//    if (!(p_piece->isKing())) {
//        //assert("The piece found at the position is not a king!");
//        return false;
//    }
//    return true;
//}
//
///*      PROMOTION
// * ----------------------------------------------------------*/
//void ChessModel::pawnPromotion(Position const & pos){
//    char promo;
//    std::string pieces{"rhbqkpRHBQKP"};
//
//    // check if the piece is a pawn to promote
//    auto&[p_piece,hasMoved] =m_board.at(pos);
//    if(!p_piece->isPromoted(pos)) return;
//
//    // ask user
//    std::cout << "Pawn promotion, choose between r, h, b and q" << std::endl;
//    while(!( std::cin >> promo) || pieces.find(promo)==std::string::npos ){
//        std::cout << "Please, choose between r, h, b and q" << std::endl;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    }
////    promotion(promo, pos);
//
//}
//
////void ChessBoard::promotion(char const &promo, Position const & pos){
////    auto&[p_piece,hasMoved] =m_board.at(pos);
////    Color color=p_piece->getColor();
////    // erase pos+pawn of the board
////    m_board.erase(pos);
////    // create the new piece & add the piece to the board
////    createPiece(tolower(promo),pos,color);
////}
//
//int ChessModel::compute_score(Color color){
//    auto score{0};
//    auto coef{1};
//    auto value{0};
//    auto letter{false};
//    auto number{false};
//    std::string center_letters{"cefg"};
//    // compute score = number of pieces on the board of the current color
//    for (auto const & b : m_board) {
//        auto&[p_piece, hasMoved] = b.second;
//        if (color == p_piece->getColor()) {
//            value = p_piece->getValue();
//            if (center_letters.find(b.first.getX())!=std::string::npos) letter = true;
//            if (b.first.getY()>=3 && b.first.getY()<=6) number = true;
//            if(letter || number) coef = 2;
//            if(letter && number) coef = 3;
//        }
//        score +=coef*value;
//    }
//return score;
//}
//

/* ----------------------------------------------------------
 *      SETTER/ GETTER
 * ----------------------------------------------------------*/


/// @brief Change the score of white or black
/// @param value of the piece eaten
/// @param color of the winner (the one whom the score is changed)
void ChessModel::setScore(int const & value, Color const & color){
    switch (color){
        case Color::WHITE:
            m_scoreW += value;
            break;
        case Color::BLACK:
            m_scoreB += value;
            break;
    }
}

/// @brief Getter of score for the white
/// @return score of white
int ChessModel::getScoreW() const{
    return m_scoreW;
}

/// @brief Getter of score for the black
/// @return score of black
int ChessModel::getScoreB() const{
    return m_scoreB;
}

void ChessModel::printScores(){
    std::cout << "The score of WHITE is : " << m_scoreW << std::endl;
    std::cout << "The score of BLACK is : " << m_scoreB << std::endl;
}

void ChessModel::printActiveColor()const{
    switch (m_color_active) {
        case Color::WHITE:
            std::cout << "*** WHITE start playing ***" << std::endl;
            break;
        case Color::BLACK:
            std::cout << "*** BLACK start playing ***" << std::endl;
            break;
    }
}

/// @brief Take boolean castling depending on color
/// @param the color to be set active
bool ChessModel::getCastling(Color color)const{
    switch (color) {
        case Color::WHITE:
            return m_castlingW;
            break;
        case Color::BLACK:
            return m_castlingB;
            break;
    }
}

void ChessModel::setCastling(bool castling, Color color){
    switch (color) {
        case Color::WHITE:
            m_castlingW = castling;
            break;
        case Color::BLACK:
            m_castlingB = castling;
            break;
    }
}

//
//char ChessModel::getPieceType(Position const & pos)const{
//    auto[p_piece,hasMoved] =m_board.at(pos);
//    return p_piece->getType();
//}
//
//Color ChessModel::getColorfromChar(char c)const{
//    Color color_active;
//    if (tolower(c)=='w'){
//        return Color::WHITE;
//    }
//    else if (tolower(c)=='b'){
//        return Color::BLACK;
//    }
//    else{
//        assert("Bad starting color : choose between 'w' (white) and 'b' (black)");
//    }
//}
//
//Color ChessModel::getColorActive()const{
//    return m_color_active;
//}

/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/

/// @brief Switch the active color
/// @param the color to be set active
Color switch_color(Color color){
    switch (color) {
        case Color::WHITE:
            return Color::BLACK;
            break;
        case Color::BLACK:
            return Color::WHITE;
            break;
    }
}

/// @brief Change board format into a vector of char
/// @details Each piece is represented by a char : r(rook), p(pawn),
/// h(knight), b(bishop), q(queen), k(king)
//std::vector<char> ChessModel::chessBoardToChar() const{
//    std::vector<char> print_board(AbstractChessModel::m_lines*AbstractChessModel::m_lines,' ');
//    for (auto const & b : m_board){
//        auto&[p_piece,hasMoved] = b.second;
//        print_board[(b.first).getCoord()] = p_piece->getType();
//    }
//    return print_board;
//}

std::vector<char> ChessModel::chessBoardToChar() const{
    return m_board->boardToChar();
}



/// @brief Switch the active color
/// @param the color to be set active
Color switch_color(char c){
    Color color = Color::WHITE;
    if (isupper(c)) color = Color::BLACK;
    return switch_color(color);
}

std::ostream& operator<<(std::ostream& os , Color color){
    switch (color) {
        case Color::WHITE:
            return os << "white";
            break;
        case Color::BLACK:
            return os << "black";
            break;
    }
}


//ChessModel play(ChessMove move, ChessBoard board){
//    board.movePiece(move.start_pos,move.end_pos);
//    return board;
//}


