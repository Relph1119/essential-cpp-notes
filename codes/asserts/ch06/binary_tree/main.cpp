//
// Created by HRF on 2023/1/6.
// P169~P179 实现二叉树
//
#include "binary_tree.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    BinaryTree<string> bt;
    bt.insert("Piglet");
    bt.insert("Eeyore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");

    cout << "Preorder traversal: \n";
    bt.preorder();

    bt.remove("Piglet");
    cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.preorder();

    bt.remove("Eeyore");
    cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.preorder();

    return 0;
}