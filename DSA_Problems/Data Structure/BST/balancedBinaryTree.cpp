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

    int check(TreeNode* root, int h){
        if (!root) return h;
        int left = check(root->left, h + 1);
        int right = check(root->right, h + 1);
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = check(root->left, 0);
        int right = check(root->right, 0);
        if (abs(left - right) > 1) return false;
        bool lh = isBalanced(root->left);
        bool rh = isBalanced(root->right);
        return lh && rh;
    }
};
