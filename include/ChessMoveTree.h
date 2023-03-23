

#ifndef CHESSMOVETREE_H
#define CHESSMOVETREE_H
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <string>
#include <optional>
#include "ChessBoard.h"
#include "ChessMove.h"
#include "GeneralTree.h"

using namespace std::literals;


void recursiveTree(std::shared_ptr<Node<ChessMove>>, int , ChessBoard , ColorOfPieces);

#endif //CHESMOVETREE_H