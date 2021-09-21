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
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        if (!root->left || !root->right) return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        q1.push(left), q2.push(right);
        while (!q1.empty() && !q2.empty()){
            if (q1.size() != q2.size()) return false;
            TreeNode* curr1 = q1.front();
            q1.pop();
            TreeNode* curr2 = q2.front();
            q2.pop();

            if (curr1 == nullptr && curr2 == nullptr) continue;
            if (!curr1 || !curr2) return false;

            if (curr1->val != curr2->val) return false;

            if (curr1->left != nullptr) q1.push(curr1->left);
            else q1.push(nullptr);
            if (curr1->right != nullptr) q1.push(curr1->right);
            else q1.push(nullptr);


            if (curr2->right != nullptr) q2.push(curr2->right);
            else q2.push(nullptr);
            if (curr2->left != nullptr) q2.push(curr2->left);
            else q2.push(nullptr);
        }
        return q1.size() == q2.size();
    }
};
