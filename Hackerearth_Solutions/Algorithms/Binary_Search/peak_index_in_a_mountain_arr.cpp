class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid - 1] <= arr[mid] && arr[mid] >= arr[mid + 1])
                return mid;
            else if (arr[mid - 1] >= arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
