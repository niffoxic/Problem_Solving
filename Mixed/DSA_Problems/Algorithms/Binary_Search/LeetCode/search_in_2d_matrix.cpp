
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target){
                int res = lower_bound(matrix[mid].begin(), matrix[mid].end(), target) - matrix[mid].begin();
                if (matrix[mid][res] == target){
                    return true;
                }
                return false;
            }else if (matrix[mid][0] > target){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return false;
    }
};
