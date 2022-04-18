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
    set<int> st;
    void helper(TreeNode *root) {
        if (!root) return;
        st.insert(root->val);
        helper(root->left);
        helper(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        helper(root);
        for (auto ans:st) {
            k--;
            if (!k) return ans;
        }
        return 0;
    }
};
