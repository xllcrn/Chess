#include "Board.h"
#include <cassert>

Board::Board(std::string const & str){
fillBoard(str);
//        std::cout << " assign board";
//        if constexpr (std::same_as<std::vector<value>, m_container>){m_container.assign(64,nullptr);}
}

void Board::fillBoard(std::string const & board_str) {
    auto rank=0;
    auto i=-1;
    std::string abc{"abcdefgh"};

    for (auto const & C : board_str){
        ++i;
        if(std::isdigit(C)) continue;
        if (C=='/') {
            i = -1;
            ++rank;
        }
        else{
            if (rank>8) assert("Bad string initialization to set boardchess pieces. Too much characters");
            Position pos=Position::create(abc[i],rank+1);
            auto p_piece = m_pieceFactory.make_piece(C);
            if (p_piece!=nullptr) {
                insertPiece(pos.getIndex(),p_piece);
            }
        }
    }
}

value_type Board::getPiece(key_type const & k) {
    const_iterator iter = m_container.find(k);
    if (isPiece(k)) return iter->second;
    return nullptr;
}

void Board::deletePiece(key_type const & k) {
    value_type p_piece = getPiece(k);
    m_deletedPiece.emplace_back(p_piece);
    erasePiece(k);
}

void Board::erasePiece(key_type const & k) {
    m_container.erase(k);
}

void Board::movePiece(Move const & move) {
    value_type p_piece = getPiece(move.start_pos);
    erasePiece(move.start_pos);
    insertPiece(move.end_pos,p_piece);
}

bool Board::movePieceForward(Move const & move) {
    bool pieceDeleted{false};
    if (isPiece(move.end_pos)) {
        pieceDeleted = true;
        deletePiece(move.end_pos);
    }
    movePiece(move);
    return pieceDeleted;
}

void Board::movePieceBackward(Move const & move, bool const & isPieceDeleted) {
    Move move_reverse= reverse(move);
    movePiece(move_reverse);
    if (isPieceDeleted) {
        assert(!m_deletedPiece.empty() && "Vector of deleted pieces should not be empty");
        value_type p_piece_deleted = m_deletedPiece.back();
        insertPiece(move.end_pos, p_piece_deleted);
    }
}

bool Board::isPiece(key_type const & k) {
    return (m_container.find(k) != m_container.end());
}

void Board::insertPiece (key_type const &k, value_type const &t){
    if (t->isKingW()) m_kingW = k;
    if (t->isKingB()) m_kingB = k;
    m_container.emplace(std::make_pair(k, t));
};

void Board::state()const{
    std::cout << "--- State of the board --- \n";
    for (auto e : m_container){
        std::cout << "Piece on the board at position : "<< e.second << " " <<convertToPosition(e.first) << (e.second)->getType() << "\n";
    }
};

//void Board::setkingPosition(Position const & pos, Color color){
//    if (color==Color::WHITE) m_kingW = pos.getBitboard();
//    if (color==Color::BLACK) m_kingB = pos.getBitboard();
//}

int Board::getkingPosition(char const & king)const{
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

std::string Board::printBoard() const{
    std::ostringstream oss;
    for(typename const_iterator it = m_container.begin();it != m_container.end(); ++it) {
        oss << it->second->getType() << '\n';
    }
    return oss.str();
}

std::vector<char> Board::boardToChar() const{
    std::vector<char> print_board(m_lines*m_lines,' ');
    for (auto const & b : m_container) print_board[b.first] = b.second->getType();
//    std::reverse(print_board.begin(),print_board.end());
    return print_board;
}

std::string Board::boardToString() const{
    std::string str;
    auto count = 0;
    std::vector<char> vect = boardToChar();
    for (auto const & e : vect) {
        if (count!=0 && count%(8)==0) str.push_back('/');
        if (e ==' ')
            str.push_back('8');
        else
            str.push_back(e);
        ++count;
    }
    return str;
}

std::tuple<Bitboard,Bitboard> Board::boardToBit() const{
    Bitboard bbW{0};
    Bitboard bbB{0};
    for (auto const & b : m_container) {
        auto color = b.second->getColor();
        switch(color){
            case Color::WHITE :
                bbW = setBit(bbW, b.first);
                break;
            case Color::BLACK :
                bbB = setBit(bbB, b.first);
                break;
        }
    }
    return std::make_tuple(bbW, bbB);
}

std::ostream& operator<<(std::ostream& os, Board board){
    os << "--- State of the board --- \n";
    for (auto e : board.m_container){
        std::cout << "Piece on the board at position : "<< e.second << " " <<convertToPosition(e.first) << (e.second)->getType() << "\n";
    }
    return os;
}


