//
// Created by Andrés Torres on 11/10/24.
//

#ifndef NODE_H
#define NODE_H

class Node {
private:
    Node* left;
    Node* right;
    int data;
public:
    Node(int value): data(value),left(nullptr),right(nullptr){}
    void setLeft(Node* left);
    void setRight(Node* right);
    void setData(int data);
    Node* getLeft();
    Node* getRight();
    int getData();
};

#endif //NODE_H
