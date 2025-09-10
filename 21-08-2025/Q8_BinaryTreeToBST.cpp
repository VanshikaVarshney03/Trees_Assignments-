#include <iostream>
#include <vector>
#include <algorithm>
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

void inorderAssign(Node* root, vector<int>& v, int& i) {
    if (!root) return;
    inorderAssign(root->left, v, i);
    root->data = v[i++];
    inorderAssign(root->right, v, i);
}

Node* binaryTreeToBST(Node* root) {
    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());
    int i=0;
    inorderAssign(root, v, i);
    return root;
}
