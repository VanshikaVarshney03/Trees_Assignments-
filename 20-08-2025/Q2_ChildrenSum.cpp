#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isChildrenSum(Node* root) {
    if (!root || (!root->left && !root->right)) return true;
    int sum = 0;
    if (root->left) sum += root->left->data;
    if (root->right) sum += root->right->data;
    return (root->data == sum) && isChildrenSum(root->left) && isChildrenSum(root->right);
}
