class Solution {
public:

    vector<int> twoSum(vector<int>& arr, int target) {
        int i = 0, j = arr.size() - 1;
        while(i < j){
            if (arr[i] + arr[j] == target) return {i + 1, j + 1};
            else if(arr[i] + arr[j] > target) j--;
            else i++;
        }
        return {-1, -1};
    }
};
