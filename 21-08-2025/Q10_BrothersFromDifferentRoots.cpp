#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int countBrothers(Node* root) {
    if (!root) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0;i<sz;i++) {
            Node* node = q.front(); q.pop();
            if (node->left && node->right) count++;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return count;
}
