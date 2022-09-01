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
    int dfs(TreeNode* head, int x){
        if(!head) return 0;
        int l = 0;
        if(head->val >= x){
            x = head->val;
            l = 1;
        }
        return l + dfs(head->left, x) + dfs(head->right, x);
    }
    
    int goodNodes(TreeNode* head) {
        return dfs(head, head->val);
    }
};
