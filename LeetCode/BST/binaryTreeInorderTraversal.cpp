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
    vector<int>ans;
    void res(TreeNode* root){
        if (!root) return;
        res(root->left);
        ans.push_back(root->val);
        res(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        res(root);
        return ans;
    }
};
