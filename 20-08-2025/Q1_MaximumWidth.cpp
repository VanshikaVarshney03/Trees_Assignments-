/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
         if (!root) return 0;

        int maxWidth = 0;
        // Queue stores pair<TreeNode*, index>
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long leftIndex = q.front().second; // index of first node
            unsigned long long rightIndex = leftIndex;

            for (int i = 0; i < size; i++) {
                auto nodePair = q.front(); q.pop();
                TreeNode* node = nodePair.first;
                unsigned long long idx = nodePair.second - leftIndex; // normalize index
                rightIndex = idx;

                if (node->left) q.push({node->left, idx * 2 + 1});
                if (node->right) q.push({node->right, idx * 2 + 2});
            }

            maxWidth = max(maxWidth, (int)(rightIndex + 1));
        }

        return maxWidth;
    }
};