#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, unordered_set<int>& s) {
    if (!root) return;
    inorder(root->left, s);
    s.insert(root->data);
    inorder(root->right, s);
}

vector<int> commonNodes(Node* root1, Node* root2) {
    unordered_set<int> s;
    vector<int> res;
    inorder(root1, s);
    function<void(Node*)> f = [&](Node* r) {
        if (!r) return;
        f(r->left);
        if (s.count(r->data)) res.push_back(r->data);
        f(r->right);
    };
    f(root2);
    return res;
}
