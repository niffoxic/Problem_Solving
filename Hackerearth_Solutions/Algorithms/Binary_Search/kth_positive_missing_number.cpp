class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int left = 0, right = arr.size() - 1;
        int nPresent = arr[right] - right - 1;
        if (nPresent < k) return arr[right] + (k - nPresent);
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            nPresent = arr[mid] - mid - 1;
            if (nPresent >= k)
                right = mid - 1;
            else left = mid + 1;
        }
        return k + right + 1;
    }
};
