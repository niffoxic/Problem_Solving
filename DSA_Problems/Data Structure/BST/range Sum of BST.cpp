class Solution {
public:

    void iot(TreeNode* root, int left, int right, int& res){
        if (root){
            iot(root->left, left, right, res);
            if (root->val >= left && root->val <= right) res += root->val;
            iot(root->right, left ,right, res);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        iot(root, low, high, res);
        return res;
    }
};
