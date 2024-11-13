//
// Created by Andrés Torres on 18/10/24.
//

#include "AVL.h"
#include <iostream>
using namespace std;
Node* AVL::insertRec(Node* root, int data) {
    if(root == nullptr) {
        return new Node(data);
    }
    if(data>root->getData()) {
        root->setRight(insertRec(root->getRight(),data));
    }else {
        root->setLeft(insertRec(root->getLeft(),data));
    }
    int bf= calculateBF(root);
    if(bf>1 && data < root->getLeft()->getData()) {
        return rotateRight(root);
    }
    if(bf<-1 && data > root->getRight()->getData()) {
        return rotateLeft(root);
    }
    if(bf>1 && data > root->getLeft()->getData()) {
        return rotateDoubleRight(root);
    }
    if(bf<-1 && data < root->getRight()->getData()) {
        return rotateDoubleLeft(root);
    }
}

void AVL::insert(int data) {
    root=insertRec(root,data);
}

void AVL::preorderRec(Node* root) {
    if(root!=nullptr){
        cout<<root->getData()<<",";
        preorderRec(root->getLeft());
        preorderRec(root->getRight());
    }
}

void AVL::posorderRec(Node* root) {
    if(root!=nullptr){
        posorderRec(root->getLeft());
        posorderRec(root->getRight());
        cout<<root->getData()<<",";;
    }

}
void AVL::inorderRec(Node* root) {
    if(root!=nullptr){
        inorderRec(root->getLeft());
        cout<<root->getData()<<",";
        inorderRec(root->getRight());
    }

}

void AVL::preorder(){
    preorderRec(root);
    cout<<endl;
}
void AVL::posorder(){
    posorderRec(root);
    cout<<endl;
}
void AVL::inorder(){
    inorderRec(root);
    cout<<endl;
}

int AVL::calculateHeightRec(Node *root) {
    if(root == nullptr) {
        return -1;
    }
    int leftHeight= calculateHeightRec(root->getLeft());
    int rightHeight= calculateHeightRec(root->getRight());

    return max(leftHeight,rightHeight) + 1;
}

int AVL::calculateHeight() {
    return calculateHeightRec(root);
}

int AVL::calculateBF(Node* root) {
    if(root==nullptr) {
        return 0;
    }
    return calculateHeightRec(root->getLeft())-calculateHeightRec(root->getRight());
}

Node *AVL::rotateRight(Node *root) {
    Node* newRoot= root->getLeft();
    newRoot->setRight(root);
    root->setLeft(newRoot->getRight());
    return newRoot;
}

Node *AVL::rotateLeft(Node *root) {
    Node* newRoot= root->getRight();
    newRoot->setLeft(root);
    root->setRight(newRoot->getLeft());
    return newRoot;
}

Node *AVL::rotateDoubleRight(Node *root) {
    root->setLeft(rotateLeft(root->getLeft()));
    return rotateRight(root);
}

Node *AVL::rotateDoubleLeft(Node *root) {
    root->setRight(rotateRight(root->getRight()));
    return rotateLeft(root);
}

Node *AVL::minValueNode(Node *root) {
    Node* current= root;
    while(current->getLeft()!=nullptr) {
        current= current->getLeft();
    }
    return current;
}


Node *AVL::deleteNodeRec(Node *root, int data) {
    if(!root) {
        return root;
    }
    if(data < root->getData()) {
        root->setLeft(deleteNodeRec(root->getLeft(),data));
    }
    else if(data > root->getData()) {
        root->setRight(deleteNodeRec(root->getRight(),data));
    }
    else {
        if(!root->getLeft()||!root->getRight()) {
            Node* temp= root->getLeft()!=nullptr ? root->getLeft() : root->getRight();
            if(!temp) {
                temp=root;
                root= nullptr;
            }else {
                *root=*temp;
            }
            delete temp;
        }else {
            Node* temp =minValueNode(root->getRight());
            root->setData(temp->getData());
            root->setRight(deleteNodeRec(root->getRight(),temp->getData()));
        }
    }
    if(!root) {
        return root;
    }
    int bf= calculateBF(root);
    if(bf>1 && data < root->getLeft()->getData()) {
        return rotateRight(root);
    }
    if(bf<-1 && data > root->getRight()->getData()) {
        return rotateLeft(root);
    }
    if(bf>1 && data > root->getLeft()->getData()) {
        return rotateDoubleRight(root);
    }
    if(bf<-1 && data < root->getRight()->getData()) {
        return rotateDoubleLeft(root);
    }
    return root;
}
