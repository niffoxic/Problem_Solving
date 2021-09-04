class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bound = 0;
        while(bound < matrix.size()){
            int left = 0, right = matrix[bound].size() - 1;
            while(left <= right){
                int mid = left + ((right - left) >> 1);
                if (matrix[bound][mid] == target)
                    return true;
                else if (matrix[bound][mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            bound++;
        }
        return false;
    }
};
