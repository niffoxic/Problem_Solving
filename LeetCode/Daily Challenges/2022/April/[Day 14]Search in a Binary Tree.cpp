class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return searchBST(root->val > val ? root->left : root->right, val);
    }
};
