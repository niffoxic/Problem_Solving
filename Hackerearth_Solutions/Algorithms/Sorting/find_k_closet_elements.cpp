class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;

        while(right - left >= k){
            if (abs(arr[right] - x) < abs(arr[left] - x))
                left++;
            else right--;
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
