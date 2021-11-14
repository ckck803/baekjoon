#include <bits/stdc++.h>
using namespace std;

int sumLevel = 0;

class Node {
   private:
    int value;

    Node* left = NULL;
    Node* right = NULL;

   public:
    Node(int value) : value(value) {}

    int getValue() {
        return value;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }

    void setLeft(Node* node) {
        this->left = node;
    }

    void setRight(Node* node) {
        this->right = node;
    }
};

Node* insert(Node* root, Node* node, int level) {
    if (root == NULL) {
        sumLevel += level;
        return node;
    }

    if (root->getValue() > node->getValue()) {
        root->setLeft(insert(root->getLeft(), node, level + 1));
    } else {
        root->setRight(insert(root->getRight(), node, level + 1));
    }
    return root;
}

int main(void) {
    int value;
    Node* tree = NULL;
    while (~scanf("%d", &value)) {
        tree = insert(tree, new Node(value), 0);
    }
    printf("%d\n", sumLevel);
    return 0;
}