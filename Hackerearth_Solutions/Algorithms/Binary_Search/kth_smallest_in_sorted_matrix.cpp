class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>res;
        unsigned int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res.push(matrix[i][j]);
                if (res.size() > k)
                    res.pop();
            }
        }
        return res.top();
    }
};
