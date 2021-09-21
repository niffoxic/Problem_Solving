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
    vector<string>res;
    void ans(TreeNode* root, string path){
        if (!root->left && !root->right) res.push_back(path);
        if (root->left) ans(root->left, path + "->" + to_string(root->left->val));
        if (root->right) ans(root->right, path + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        path += to_string(root->val);
        ans(root, path);
        return res;
    }
};
