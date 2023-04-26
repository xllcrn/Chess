#ifndef CPP_CHESSGAME_BOARD_H
#define CPP_CHESSGAME_BOARD_H

#include <unordered_map>
#include <map>
#include "Position.h"
#include "Piece.h"
#include "PieceFactory.h"
#include "ChessMove.h"
#include <concepts>
#include <iostream>
#include <cassert>
using key_type = int ;
using value_type = std::shared_ptr<Piece> ;

class Board{
private:
    int m_lines=8;
    int m_kingW = -1;
    int m_kingB = -1;
    std::unordered_map<key_type,value_type> m_container;
    BuildPieceFactory m_pieceFactory;
    std::vector<std::shared_ptr<Piece>> m_deletedPiece;
    bool lastPieceHasMoved;
public:
    typedef std::unordered_map<key_type,value_type>::iterator iterator;
    typedef std::unordered_map<key_type,value_type>::const_iterator const_iterator ;
    Board(std::string const & str);
    void state()const;

    iterator begin() { return m_container.begin(); }
    iterator end() { return m_container.end(); }

    const_iterator cbegin() const { return m_container.begin(); }
    const_iterator cend() const { return m_container.end(); }

    size_t size() const { return m_container.size(); }

    void insertPiece (key_type const &k, value_type const &t);
//    void setkingPosition(Position const & pos, Color color);
    int getkingPosition(char const & king)const;
    std::string printBoard()const;
    std::vector<char> boardToChar() const;
    std::string boardToString() const;
    void fillBoard(std::string const & board_str) ;
    value_type getPiece(key_type const & k) ;
    void deletePiece(key_type const & k) ;
    void erasePiece(key_type const & k) ;
    void movePiece(Move const & move) ;
    bool movePieceForward(Move const & move) ;
    void movePieceBackward(Move const & move, bool const &) ;
    bool isPiece(key_type const & k) ;
    std::tuple<Bitboard,Bitboard> boardToBit() const;
    friend std::ostream& operator<<(std::ostream& os, Board board);
};



#endif //CPP_CHESSGAME_BOARD_H
