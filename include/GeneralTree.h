// CPP program to do level order traversal
// of a generic tree

#ifndef CHESS_GENERALTREE_H
#define CHESS_GENERALTREE_H
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <string>
#include "ChessBoard.h"
#include "ChessMove.h"
using namespace std::literals;

// Represents a node of an n-ary tree
template <typename T>
struct Node
{
    T key;
    std::vector<std::shared_ptr<Node<T>>>child;
};

// Utility function to create a new tree node
template <typename T>
std::shared_ptr<Node<T>> newNode(T key)
{
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>> (Node<T>{key});
//    Node<T>* temp = new Node<T>;
    temp->key = key;
    return temp;
};

// Prints the n-ary tree level wise
template <typename T>
void LevelOrderTraversal(std::shared_ptr<Node<T>> root)
{
    if (root==nullptr)
        return;

    // Standard level order traversal code
    // using queue
    std::queue<std::shared_ptr<Node<T>> > q;  // Create a queue
    q.push(root); // Enqueue root
    while (!q.empty())
    {
        int n = q.size();

        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            std::shared_ptr<Node<T>>  p = q.front();
            q.pop();
            std::cout << p->key << " ";

            // Enqueue all children of the dequeued item
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }

        std::cout << std::endl; // Print new line between two levels
    }
};

template <typename T>
void printBranches(std::shared_ptr<Node<T>> p) {
    if(p->child.empty()){
        std::cout << "end of branch" << std::endl;
        return;
    }
    for (int i = 0; i < p->child.size(); i++) {     //loop on children
//        ChessBoard board_child = play((p->child[i])->key, board_parent);
        std::cout << (p->child[i])->key << std::endl;
        printBranches(p->child[i]);
    }
}


template <typename T>
void printBT(std::string const & prefix, std::shared_ptr<Node<T>> const node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix ;

        if (isLeft){std::cout << "|--";}
        else{std::cout << "|--" ;}

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
//        if (isLeft){
        std::string prefPlus = prefix + "|        ";
        for (int i = 0; i < node->child.size(); i++) {     //loop on children
            printBT( prefPlus, node->child[i], true);
        }
//        else{
//            printBT( prefix + "    "), node->child, false);
//        }
//        printBT( prefix + (isLeft ? "│   " : "    "), node->child, true);
//        printBT( prefix + (isLeft ? "│   " : "    "), node->m_right, false);
    }
}

template <typename T>
void printBT(std::shared_ptr<Node<T>> const node)
{
    printBT(""s, node, false);
}


void createTree(std::shared_ptr<Node<ChessMove>> root, int level, ChessBoard board_root);
void recursiveTree(std::shared_ptr<Node<ChessMove>> p, int level, ChessBoard board_parent, ColorOfPieces color);

#endif //CHESS_GENERALTREE_H