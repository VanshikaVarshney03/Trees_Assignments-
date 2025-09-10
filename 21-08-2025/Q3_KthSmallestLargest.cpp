#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int kthSmallest(Node* root, int k) {
    vector<int> v;
    inorder(root, v);
    return v[k-1];
}

int kthLargest(Node* root, int k) {
    vector<int> v;
    inorder(root, v);
    return v[v.size()-k];
}
