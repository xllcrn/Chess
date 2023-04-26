

#include "Bitboard.h"

//std::ostream& operator<<(std::ostream& os, Bitboard bitboard){
//    os << "--- State of the board --- \n";
//    for (auto bit=0; bit<8*sizeof(Bitboard); bit++){
//        if (getBit(bitboard, bit)==1ULL)
//            os << "Piece on the board at position : "<< convertToPosition(bit) << "\n";
//    }
//    return os;
//}