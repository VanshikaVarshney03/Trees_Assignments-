#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool findPair(Node* root, int target, unordered_set<int>& s) {
    if (!root) return false;
    if (findPair(root->left, target, s)) return true;
    if (s.count(target-root->data)) return true;
    s.insert(root->data);
    return findPair(root->right, target, s);
}

bool twoSumBST(Node* root, int target) {
    unordered_set<int> s;
    return findPair(root, target, s);
}
