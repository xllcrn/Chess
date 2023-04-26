//#pragma once

#ifndef CPP_CHESSGAME_BITBOARD_H
#define CPP_CHESSGAME_BITBOARD_H
#include "Position.h"

using Bitboard = unsigned long long int;
using tuplBitboard = std::tuple<Bitboard,Bitboard>;

inline Bitboard setBit(Bitboard input, int const & bit) {
    return (input |= 1ULL << bit);
}

inline int getBit(Bitboard const input, int const & bit) {
//    std::cout <<"dans getBit " << (input >> bit)<<": "<<((input >> bit) & 1UL) << std::endl;
    return ((input >> bit) & 1ULL)? 1 : 0;
}

inline Bitboard clearBit(Bitboard const input, int const & bit) {
    return (input & (~(1ULL << (bit - 1ULL))));
}

inline void printBitboard(Bitboard const & input) {
//    std::string printBoard(64,' ');
    for (auto bit=0; bit<64; bit++){
        if (getBit(input, bit)==1) {
//            printBoard[bit]='x';
            std::cout << convertToPosition(bit);
        }
    }
//    std::cout << " \n le bitboard : " << input << ' ' << printBoard << std::endl;
}

inline int whichBit(Bitboard input) {
    for (auto bit=0; bit<8*sizeof(Bitboard); bit++){
        if (getBit(input, bit)==1) return bit;
    }
    return -1;
}

//std::ostream& operator<<(std::ostream& os, Bitboard bitboard);

#endif //CPP_CHESSGAME_BITBOARD_H
