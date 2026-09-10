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
    pair<int, int> dfs(TreeNode* node, int &count) {
        if (!node) return {0, 0};

        auto [leftSum, leftNodes] = dfs(node->left, count);
        auto [rightSum, rightNodes] = dfs(node->right, count);

        int currentSum = leftSum + rightSum + node->val;
        int currentNodes = leftNodes + rightNodes + 1;

        if (node->val == (currentSum / currentNodes)) {
            count++;
        }

        return {currentSum, currentNodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0; 
        dfs(root, count);
        return count;
    }
};