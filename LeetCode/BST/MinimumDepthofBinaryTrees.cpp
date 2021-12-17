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
    int mini = INT_MAX;
    int res(TreeNode* root, int d){
        if (!root) return 0;
        if (!root->left && !root->right)
            mini = min(mini, d);
        res(root->left, d + 1);
        res(root->right, d + 1);
        return mini;
    }

    int minDepth(TreeNode* root) {
        int d = 1;
        return res(root, d);
    }
};

