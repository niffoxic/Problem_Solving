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

    void getLeaf(TreeNode* root, vector<int>& res){
        stack<TreeNode*> stck;
        stck.push(root);
        while (!stck.empty()){
            TreeNode* currentPosition = stck.top();
            stck.pop();
            if (!currentPosition->left && !currentPosition->right)
                res.push_back(currentPosition->val);
            if (currentPosition->left != nullptr)
                stck.push(currentPosition->left);
            if (currentPosition->right != nullptr)
                stck.push(currentPosition->right);

        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        getLeaf(root1, r1);
        getLeaf(root2, r2);
        return r1 == r2;
    }
};
