//
// Created by Andrés Torres on 18/10/24.
//

#ifndef AVL_H
#define AVL_H

#include "Node.h"

class AVL {
private:
    Node* root;
    Node* insertRec(Node* root, int data);
    void preorderRec(Node* root);
    void posorderRec(Node* root);
    void inorderRec(Node* root);
    int calculateHeightRec(Node* root);
    int calculateBF(Node* root);
    Node* rotateRight(Node* root);
    Node* rotateLeft(Node* root);
    Node* rotateDoubleRight(Node* root);
    Node* rotateDoubleLeft(Node* root);
    Node* deleteNodeRec(Node* root, int data);
    Node* minValueNode(Node* root);
public:
    AVL():root(nullptr){}
    void insert(int data);
    void deleteNode(int data);
    void preorder();
    void posorder();
    void inorder();
    int calculateHeight();
};



#endif //AVL_H
