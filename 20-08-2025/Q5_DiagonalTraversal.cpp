#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> diagonalTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        while (node) {
            res.push_back(node->data);
            if (node->left) q.push(node->left);
            node = node->right;
        }
    }
    return res;
}
