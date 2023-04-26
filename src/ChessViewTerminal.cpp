//
// Created by xllcr on 27/03/2023.
//

#include "ChessViewTerminal.h"

/// @brief Add decorator to the board
/// @param the board converted into a vector of char
/// @return a string containing the whole board
std::string ChessViewTerminal::boardToString(std::vector<char> const & print_board){
    std::ostringstream ostr;
    auto icount=1;
    auto num_line=0;
    int lines = int(sqrt(print_board.size()));

    for (int i=97;i<=lines;i++){
        char c = i;
        ostr << c << ' ';
    }
    ostr << "\n";
    ostr << "    - - - - - - - - \n";
    auto it_end = print_board.end();
    for(auto i=0;i<lines;i++) {
        for (auto it = it_end-(i+1)*lines; it != it_end-i*lines; it++) {
            if ((icount - 1) % (lines) == 0) {
                ostr << (lines - num_line) << " | ";
            }
            ostr << *it << ' ';
            if (icount % lines == 0) {
                ostr << "| " << (lines - num_line);
                ostr << "\n";
                num_line++;
            }
            icount++;
        }
    }
    ostr << "    - - - - - - - - \n";
    for (int i=97;i<=lines;i++){
        char c = i;
        ostr << c << ' ';
    }
    ostr << "\n";

    return ostr.str();
}

/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, AbstractChessModel& model){
    os << ChessViewTerminal::boardToString(model.chessBoardToChar());
    return os;
}