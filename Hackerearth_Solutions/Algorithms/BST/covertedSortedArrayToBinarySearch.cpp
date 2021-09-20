class Solution {
public:

    TreeNode* sbt(int left, int right, vector<int>& num){
        if (left > right) return NULL;
        if (left == right) return new TreeNode(num[left]);
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = sbt(left, mid - 1, num);
        root->right = sbt(mid + 1, right, num);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sbt(0, (int)nums.size() - 1, nums);
    }
};
