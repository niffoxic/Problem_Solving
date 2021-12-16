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

    int sum = 0;

    void fetch(TreeNode* root, int mask){
        if (!root) return;
        mask = (mask << 1) | root->val;
        if (!root->left && !root->right)
            sum += mask;
        fetch(root->left, mask);
        fetch(root->right, mask);

    }

    int sumRootToLeaf(TreeNode* root) {
        fetch(root, 0);
        return sum;
    }
};
