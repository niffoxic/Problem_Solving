class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            uint counts = q.size();
            long double val = 0;
            for(int i = 0; i < counts; i++){
                TreeNode* curr = q.front();
                q.pop();
                val += curr->val;
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            res.push_back((double)val/counts);
        }
        return res;
    }
};
