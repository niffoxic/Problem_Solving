class Solution {
public:
    void inorder(TreeNode* root, TreeNode* &prev, int &res)
    {
        if (root != nullptr){
            inorder(root->left, prev, res);
            if (prev){
                res = min(res, abs(root->val - prev->val));
            }
            prev = root;
            inorder(root->right, prev, res);
        }
    }

    int minDiffInBST(TreeNode* root)
    {
        TreeNode* prev = nullptr;
        int res = INT_MAX;
        inorder(root, prev, res);
        return res;
    }
};
