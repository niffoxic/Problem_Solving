class Solution {
public:

    static bool bin(vector<int> & arr, int diff, int selected){
        int mid, left = 0, right = arr.size() - 1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if (abs(arr[mid] - selected) <= diff)
                return false;
            else if (arr[mid] > selected)
                right = mid - 1;
            else left = mid + 1;
        }
        return true;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for(auto i: arr1){
            res += bin(arr2, d, i);
        }
        return res;
    }
};
