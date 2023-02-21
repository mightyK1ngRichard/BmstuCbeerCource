//
// Created by Дмитрий Пермяков on 21.02.2023.
//

#ifndef BINSEURCH_HEADER_H
#define BINSEURCH_HEADER_H

#include <iostream>
#include "string"

class Tree {
protected:
    class Node {
    public:
        Node();
        explicit Node(const int &value);
        ~Node();

        Node *_l;
        Node *_r;
        int _data;
    };

public:
    Tree();
    ~Tree();
    void AddElement(Node *&root, const int &element);
    void PrintTree(Node *root);
    Node *_root;
};

Tree::Node::Node() : _data(0), _l(nullptr), _r(nullptr) {}
Tree::Node::Node(const int &value) : _data(value), _l(nullptr), _r(nullptr) {}
Tree::Node::~Node() {
    delete _l;
    delete _r;
}
Tree::Tree() : _root(nullptr) {}
Tree::~Tree() {
    delete _root;
}
void Tree::AddElement(Node *&root, const int &element) {
    if (!root) {
        root = new Node(element);
        return;
    }

    if (root->_data < element) {
        AddElement(root->_r, element);
        return;
    } else {
        AddElement(root->_l, element);
        return;
    }
}
void Tree::PrintTree(Node *root) {
    if (!root) {
        return;
    }

    std::cout << root->_data << std::endl;
    PrintTree(root->_r);
    PrintTree(root->_l);
}

#endif //BINSEURCH_HEADER_H
