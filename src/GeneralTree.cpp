#include <cassert>
#include "GeneralTree.h"

void createTree(std::shared_ptr<Node<ChessMove>> root, int level, ChessBoard board_root) {
//    // 1 - play moves to find the board
//
//    // 2 - find potential moves
//
//    // 3 - create children
//
    if (root == nullptr)
        return;

    std::shared_ptr<Node<ChessMove>> p0 = root;

    // initialize children of the root
    std::vector<ChessMove> vectMoves;
    vectMoves = board_root.potentialMoves(ColorOfPieces::WHITE);

    // create level 1
    for (auto const &move : vectMoves) {
        (root->child).push_back(newNode<ChessMove>(move));
    }

    // create level 2
    ChessBoard board_parent(board_root);
    for (int i = 0; i < p0->child.size(); i++){     //loop on children
        ChessBoard board_child = play( (p0->child[i])->key, board_parent);  //move of the current child
        vectMoves = board_child.potentialMoves(ColorOfPieces::BLACK);
        for (auto const &move : vectMoves) {
            (p0->child[i]->child).push_back(newNode<ChessMove>(move));
        }
    }

    // create level 3
    for (int i = 0; i < p0->child.size(); i++) {     //loop on children
        ChessBoard board_child = play( (p0->child[i])->key, board_parent);  //move of the current child
        for (int j = 0; j < (p0->child[i]->child).size(); j++) {     //loop on children
            ChessBoard board_child1 = play((p0->child[i])->child[j]->key, board_child);  //move of the current child
            vectMoves = board_child1.potentialMoves(ColorOfPieces::WHITE);
            for (auto const &move : vectMoves) {
                (p0->child[i]->child[j]->child).push_back(newNode<ChessMove>(move));
            }
        }
    }
//
//    // create level 4
//    for (int i = 0; i < p0->child.size(); i++) {     //loop on children
//        ChessBoard board_child = play((p0->child[i])->key, board_parent);  //move of the current child
//        for (int j = 0; j < (p0->child[i]->child).size(); j++) {     //loop on children
//            ChessBoard board_child1 = play((p0->child[i])->child[j]->key, board_child);  //move of the current child
//            for (int k = 0; k < (p0->child[i]->child[j]->child).size(); k++) {     //loop on children
//                ChessBoard board_child2 = play((p0->child[i])->child[j]->child[k]->key, board_child1);
//                vectMoves = board_child2.potentialMoves(ColorOfPieces::BLACK);
//                for (auto const &move : vectMoves) {
//                    (p0->child[i]->child[j]->child[k]->child).push_back(newNode<ChessMove>(move));
//                }
//            }
//        }
//    }

}


/// @brief Find all the potential moves of the board for pieces of color "color" of a specific level
/// @param color : the color to play
void recursiveTree(std::shared_ptr<Node<ChessMove>> p, int level, ChessBoard board_parent, ColorOfPieces color) {

    if (level <= 0) return;

    std::vector<ChessMove> vectMoves;
    // find the children and push back them
    vectMoves = board_parent.potentialMoves(color);
    for (auto const &move : vectMoves) {
        (p->child).push_back(newNode<ChessMove>(move));
    }
    for (int i = 0; i < p->child.size(); i++) {     //loop on children
        ChessBoard board_child = play((p->child[i])->key, board_parent);
        recursiveTree(p->child[i], level - 1, board_child, switch_color(color));
    }
}

