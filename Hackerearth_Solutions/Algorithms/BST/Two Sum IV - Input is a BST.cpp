struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    unordered_set<int>res;

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (res.find(k - root->val) != res.end()) return true;
        res.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};


// 2nd

class Solution {
public:
    vector<int> res;

    void iot(TreeNode* root){
        if (root){
            iot(root->left);
            res.push_back(root->val);
            iot(root->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        iot(root);
        int left = 0, right = res.size() - 1;
        sort(res.begin(), res.end());
        while (left < right){
            if (res[left] + res[right] == k) return true;
            else if (res[left] + res[right] > k) right--;
            else left++;
        }
        return false;
    }
};


// 3rd
class Solution {
public:
    vector<int> res;

    void iot(TreeNode* root){
        if (root){
            iot(root->left);
            res.push_back(root->val);
            iot(root->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        iot(root);
        int left = 0, right = res.size() - 1;
        while (left < right){
            if (res[left] + res[right] == k) return true;
            else if (res[left] + res[right] > k) right--;
            else left++;
        }
        return false;
    }
};
