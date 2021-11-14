#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int value;
    Node* left;
    Node* right;

   public:
    Node(int value) : value(value), left(NULL), right(NULL) {}
};

class BST {
    Node* root;

    void insert(Node* root = this->root, int value) {
        if (root == NULL) {
        }

        if (root->value > value) {
        }
        if (root->value < value) {
        }
    }

}

int
main(void) {
    int value;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    Node* BST = NULL;
    while (cin >> value) {
        BST->insert(value);
    }
    BST->postOrder();
    return 0;
}