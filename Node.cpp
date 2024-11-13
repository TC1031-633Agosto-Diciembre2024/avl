//
// Created by Andrés Torres on 11/10/24.
//

#include "Node.h"

void Node::setLeft(Node* left) {
    this->left=left;
}
void Node::setRight(Node* right) {
    this->right=right;
}
void Node::setData(int data) {
    this->data= data;
}
Node* Node::getLeft() {
    return left;
}
Node* Node::getRight() {
    return right;
}
int Node::getData() {
    return data;
}