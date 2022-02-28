class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        int res = 1;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max(res, end - start + 1);
            for (int i = 0; i < cnt; ++i) {
                pair<TreeNode *, int> p = q.front();
                int idx = p.second - start;
                q.pop();
                if (p.first->left != nullptr)
                    q.push({p.first->left, (long long) 2 * idx + 1});
                if (p.first->right != nullptr)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        return res;
    }
};
