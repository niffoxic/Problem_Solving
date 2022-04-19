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
    TreeNode *f, *s, *p;

    void recoverTree(TreeNode *root) {
        p = new TreeNode(INT_MIN);
        inorder(root);
        swap(f->val, s->val);
    }

    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (f == nullptr && root->val < p->val) f = p;
        if (f != nullptr && root->val < p->val) s = root;
        p = root;
        inorder(root->right);
    }
};
