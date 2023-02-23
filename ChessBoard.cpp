//
// Created by xllcr on 21/02/2023.
//

#include "ChessBoard.h"
#include "Position.h"
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include "Pawn.h"
int ChessBoard::m_lines=8;

/* Default constructor */
ChessBoard::ChessBoard(){
//  Create the pieces of the chessboard : WHITE
    piecesSet(ColorOfPieces::WHITE);
//
////  Create the pieces of the chessboard : BLACK
    piecesSet(ColorOfPieces::BLACK);

}

void ChessBoard::piecesSet(ColorOfPieces color){
    int rank, rankp;
    std::string type;
    std::string abc{"abcdefgh"};
    switch (color) {
        case ColorOfPieces::WHITE:
            type = "rhbkqp";
            rank = 1;
            rankp= 2;
            break;
        case ColorOfPieces::BLACK:
            type="RHBKQP";
            rank=8;
            rankp= 7;
            break;
    }

//    // Rooks (tours)
    m_board.insert({Position{'a',rank}, Piece(type[0],color,Position{'a',rank} )});       //rooks (tours)
    m_board.insert({Position{'h',rank}, Piece(type[0],color,Position{'h',rank} )});       //rooks (tours)
//    // Knights/Horse (cavaliers)
    m_board.insert({Position{'b',rank}, Piece(type[1],color,Position{'b',rank} )});       //horse (cavaliers)
    m_board.insert({Position{'g',rank}, Piece(type[1],color,Position{'g',rank} )});       //horse (cavaliers)
//    // Bishop (fous)
    m_board.insert({Position{'c',rank}, Piece(type[2],color,Position{'c',rank} )});       //bishop (fous)
    m_board.insert({Position{'f',rank}, Piece(type[2],color,Position{'f',rank} )});       //bishop (fous)
//    // King/queen (roi/reine)
    m_board.insert({Position{'e',rank}, Piece(type[3],color,Position{'e',rank} )});       //king (roi)
    m_board.insert({Position{'d',rank}, Piece(type[4],color,Position{'d',rank} )});       //queen (reine)
//    // Pawn (pions)
    for (char & elem : abc) {
        m_board.insert({Position{elem,rankp}, Piece(color,Position{elem,rankp} )});
    }

}


///* Copy constructor */
//ChessBoard::ChessBoard(ChessBoard const & b) {
//    copy(b.m_board.begin(), b.m_board.end(), back_inserter(m_board));
//}

/* Destructor */
ChessBoard::~ChessBoard() {}

/* Print chessboard */
std::string ChessBoard::toString(){
    std::ostringstream ostr;
    int icount=1;
    int num_line=0;
    int coord;
    std::string abc{"  abcdefgh"};
    std::vector<char> print_board(m_lines*m_lines,' ');

    std::map<Position, Piece>::iterator it;
    for (it = m_board.begin(); it != m_board.end(); ++it){
                //coord = it->first ;//.getCoord();
        Position pos{it->first} ;
        Piece piece{it->second};
        print_board[pos.getCoord()] = piece.getType();
    }

    for (auto& elem : abc){
        ostr << elem << ' ';
    }
    ostr << "\n";
    ostr << "    - - - - - - - - \n";
    auto it_end = print_board.end();
    for(int i=0;i<8;i++) {
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

//std::string ChessBoard::to_string() {
//    std::ostringstream ostr;
//    for (auto& elem: m_board){
//        Position pos{elem.first};
//        Piece p_p{elem.second};
//        std::cout << pos;
//        std::cout << p_p;
//    }
//    return ostr.str();
//}

std::ostream& operator<<(std::ostream& os, ChessBoard& p){
    os << p.toString();
    return os;
}

//std::ostream& operator<<(std::ostream& os, ChessBoard& board){
////    os << board.to_string();
//
//        for (auto& elem: board.m_board){
//            Position pos{elem.first};
//            Piece p_p{elem.second};
//            os<< "coucou" << pos;
//            os << "type de piece " << (p_p).getType();
//        }
//    return os;
//}

///* Convert position to coordinate into vector m_board */
//int ChessBoard::position2coordinate(Position & pos){
//    int coord;
//    char letter = pos.getX();
//    int col = pos.getY();
//    int lin = letter-96;
//    coord = (col-1)*m_lines+lin;
//    return coord;
//}

/* Move a prawn */
void ChessBoard::movePiece(Position& pBefore, Position& pAfter){
    Piece piece;
    piece = m_board[pBefore];
    if (piece.isValid(pAfter)){
//        auto const node = m_board.extract(piece.getPosition());
//        node.key() = pAfter;
//        m_board.emplace(std::move(node.key()), std::move(node.mapped()));
        piece.setPosition(pAfter);
        m_board[pAfter] = piece;
        m_board.erase(pBefore);
    }
    Position pos {piece.getPosition()};
    std::cout << "nouvelle pos?" << pos << std::endl;
    std::cout << m_board[pAfter];
}

//void ChessBoard::move(Position&& before, Position&& after){
//    int coord_before = position2coordinate(before);
//    int coord_after = position2coordinate(after);
//    char pion_before = m_board[coord_before];
//    m_board[coord_after] = pion_before;
//    m_board[coord_before] = ' ';
//}