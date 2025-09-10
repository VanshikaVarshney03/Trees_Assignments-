#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isDeadEnd(Node* root, unordered_set<int>& s, int minVal, int maxVal) {
    if (!root) return false;
    if (minVal == maxVal) return true;
    return isDeadEnd(root->left, s, minVal, root->data-1) || isDeadEnd(root->right, s, root->data+1, maxVal);
}

bool BSTDeadEnd(Node* root) {
    unordered_set<int> s;
    return isDeadEnd(root, s, 1, INT_MAX);
}
