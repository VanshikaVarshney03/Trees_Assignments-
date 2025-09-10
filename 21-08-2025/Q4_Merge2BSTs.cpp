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

Node* sortedArrayToBST(vector<int>& v, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l+r)/2;
    Node* root = new Node(v[mid]);
    root->left = sortedArrayToBST(v, l, mid-1);
    root->right = sortedArrayToBST(v, mid+1, r);
    return root;
}

Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> v1, v2, merged;
    inorder(root1, v1);
    inorder(root2, v2);
    int i=0, j=0;
    while(i<v1.size() && j<v2.size()) {
        if(v1[i]<v2[j]) merged.push_back(v1[i++]);
        else merged.push_back(v2[j++]);
    }
    while(i<v1.size()) merged.push_back(v1[i++]);
    while(j<v2.size()) merged.push_back(v2[j++]);
    return sortedArrayToBST(merged,0,merged.size()-1);
}
