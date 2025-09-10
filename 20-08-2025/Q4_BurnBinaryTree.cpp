#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int minTimeToBurnTree(Node* root, int target) {
    if (!root) return 0;
    unordered_map<Node*, Node*> parent;
    queue<Node*> q;
    q.push(root);
    Node* targetNode = nullptr;
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (node->data == target) targetNode = node;
        if (node->left) { parent[node->left] = node; q.push(node->left); }
        if (node->right) { parent[node->right] = node; q.push(node->right); }
    }
    unordered_map<Node*, bool> visited;
    queue<Node*> burnQ;
    burnQ.push(targetNode);
    visited[targetNode] = true;
    int time = 0;
    while (!burnQ.empty()) {
        int sz = burnQ.size();
        bool burned = false;
        for (int i = 0; i < sz; i++) {
            Node* node = burnQ.front(); burnQ.pop();
            if (node->left && !visited[node->left]) { visited[node->left]=true; burnQ.push(node->left); burned=true; }
            if (node->right && !visited[node->right]) { visited[node->right]=true; burnQ.push(node->right); burned=true; }
            if (parent.count(node) && !visited[parent[node]]) { visited[parent[node]]=true; burnQ.push(parent[node]); burned=true; }
        }
        if (burned) time++;
    }
    return time;
}
