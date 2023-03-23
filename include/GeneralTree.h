// CPP program to do level order traversal
// of a generic tree

#ifndef CHESS_GENERALTREE_H
#define CHESS_GENERALTREE_H
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <string>
#include <optional>
#include "ChessBoard.h"
#include "ChessMove.h"
using namespace std::literals;

// Represents a node of an n-ary tree
template <typename T>
struct Node
{
    std::optional<T> key;
    std::vector<std::shared_ptr<Node<T>>>child;
    std::optional<int> score;
};

// Utility function to create a new tree node
template <typename T>
std::shared_ptr<Node<T>> newNode(T key, int score)
{
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>{key});
//    Node<T>* temp = new Node<T>;
    temp->key = key;
    temp->score = score;
    return temp;
};

template <typename T>
std::shared_ptr<Node<T>> newNode()
{
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>{});
    return temp;
};


//// Prints the n-ary tree level wise
//template <typename T>
//void LevelOrderTraversal(std::shared_ptr<Node<T>> root)
//{
//    if (root==nullptr)
//        return;
//
//    // Standard level order traversal code
//    // using queue
//    std::queue<std::shared_ptr<Node<T>> > q;  // Create a queue
//    q.push(root); // Enqueue root
//    while (!q.empty())
//    {
//        int n = q.size();
//
//        // If this node has children
//        while (n > 0)
//        {
//            // Dequeue an item from queue and print it
//            std::shared_ptr<Node<T>>  p = q.front();
//            q.pop();
//            if (p->key.has_value()) std::cout << p->key.value() << " ";
//
//            // Enqueue all children of the dequeued item
//            for (int i=0; i<p->child.size(); i++)
//                q.push(p->child[i]);
//            n--;
//        }
//
//        std::cout << std::endl; // Print new line between two levels
//    }
//};
//
//template <typename T>
//void printBranches(std::shared_ptr<Node<T>> p) {
//    if(p->child.empty()){
//        std::cout << "end of branch" << std::endl;
//        return;
//    }
//    for (int i = 0; i < p->child.size(); i++) {     //loop on children
////        ChessBoard board_child = play((p->child[i])->key, board_parent);
//        std::cout << (p->child[i])->key << std::endl;
//        printBranches(p->child[i]);
//    }
//}


template <typename T>
std::string BTToString(std::shared_ptr<Node<T>> const node) {
    return BTToString(""s, node, false);
}

template <typename T>
std::string BTToString(std::string const & prefix, std::shared_ptr<Node<T>> const node, bool isLeft){
    std::ostringstream ostr;
    if( node != nullptr )
    {
        ostr <<  prefix ;
        if (node->key.has_value()) {
            // print the value of the node
            ostr << "|--" << node->key.value()<<':'<<node->score.value() << "\n";
        }
        // enter the next tree level - left and right branch
        std::string prefPlus = prefix + "|        ";
        for (int i = 0; i < node->child.size(); i++) {     //loop on children
            ostr << BTToString( prefPlus, node->child[i], true);
        }
    }
    return ostr.str();
}


/* ----------------------------------------------------------
 *      EXTERNAL
 * ----------------------------------------------------------*/
template <typename T>
std::ostream& operator<<(std::ostream& os, std::shared_ptr<Node<T>> const root){
    os << BTToString(root);
    return os;
}
#endif //CHESS_GENERALTREE_H