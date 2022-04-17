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

    TreeNode* fill_res(priority_queue<int, vector<int>, greater<>>& data){
        if(data.empty()) return nullptr;
        TreeNode* subRoot = new TreeNode(data.top());
        data.pop();
        subRoot->right = fill_res(data);
        return subRoot;
    }

    TreeNode* increasingBST(TreeNode* root) {
        priority_queue<int, vector<int>, greater<>> res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return fill_res(res);
    }
};
