
#include "ChessMoveTree.h"
/// @brief Find all the potential moves of the board for pieces of color "color" of a specific level
/// @param color : the color to play
void recursiveTree(std::shared_ptr<Node<ChessMove>> p, int level,
                    ChessBoard board_parent,
                    Color color) {

    if (level <= 0) return;

//    std::vector<ChessMove> vectMoves;
    // find the children and push back them
    auto[vectMoves,score] = board_parent.potentialMoves(color);
    for (auto const &move : vectMoves) {
        (p->child).push_back(newNode<ChessMove>(move,score));
    }
    for (int i = 0; i < p->child.size(); i++) {     //loop on children
        ChessBoard board_child = play((p->child[i])->key.value(), board_parent);

        //check if not chessmate of the switch_color before calling recursively
        char king='k';
        if (switch_color(color)==Color::BLACK) king='K';
        if (!board_child.isChessMate(ChessMateChoice::CHESSMATE,king)) {
            recursiveTree(p->child[i], level - 1, board_child, switch_color(color));
        }
    }
}

