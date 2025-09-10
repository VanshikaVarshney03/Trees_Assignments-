#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> nodesAtDistanceK(Node* root, int k) {
    vector<int> res;
    if (!root) return res;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, dist] = q.front(); q.pop();
        if (dist == k) res.push_back(node->data);
        if (node->left) q.push({node->left, dist+1});
        if (node->right) q.push({node->right, dist+1});
    }
    return res;
}
