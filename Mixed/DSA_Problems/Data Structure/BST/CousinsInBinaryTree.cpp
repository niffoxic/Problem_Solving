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
struct TreeData{
    TreeNode* node;
    int level;
    int parent;
};

class Solution {
public:

    bool isCousins(TreeNode* root, int x, int y) {
        int kx = 0, ky = 0, px = 0, py = 0;
        queue<TreeData> q;
        q.push(TreeData{root, 0, -1});
        while (!q.empty()){
            struct TreeData curr;
            curr = q.front();
            int level = curr.level, parent = curr.parent;
            q.pop();
            if (curr.node->val == x){
                kx = level;
                px = parent;
            }else if (curr.node->val == y){
                ky = level;
                py = parent;
            }
            if (kx && ky) break;
            if (curr.node->left)
                q.push(TreeData{curr.node->left, level + 1, curr.node->val});
            if (curr.node->right){
                q.push(TreeData{curr.node->right, level + 1, curr.node->val});
            }
        }
        return kx == ky && px != py;
    }
};
