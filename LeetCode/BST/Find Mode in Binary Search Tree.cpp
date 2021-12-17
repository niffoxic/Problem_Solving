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
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> res;
        int maxi = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            uint counts = q.size();
            for(int i = 0; i < counts; i++){
                TreeNode* curr = q.front();
                q.pop();
                res[curr->val]++;
                maxi = max(maxi, res[curr->val]);
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        vector<int>ans;
        for(auto i: res){
            if (i.second == maxi) ans.push_back(i.first);
        }
        return ans;
    }
};
