#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int countNodesInRange(Node* root, int low, int high) {
    if (!root) return 0;
    if (root->data < low) return countNodesInRange(root->right, low, high);
    if (root->data > high) return countNodesInRange(root->left, low, high);
    return 1 + countNodesInRange(root->left, low, high) + countNodesInRange(root->right, low, high);
}
