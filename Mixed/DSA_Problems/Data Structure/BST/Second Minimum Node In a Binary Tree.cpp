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

     int res[2] = {INT_MAX, INT_MAX};
    int set = true;
    void tr(TreeNode* root){
        if (!root) return;

        if (res[0] > root->val){
            res[1] = res[0];
            res[0] = root->val;
        }else if (res[1] >= root->val && root->val != res[0]){
            res[1] = root->val;
            set = false;
        }
            

        tr(root->left);
        tr(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        tr(root);
        if (set) return -1;
        return res[1];
    }
};
