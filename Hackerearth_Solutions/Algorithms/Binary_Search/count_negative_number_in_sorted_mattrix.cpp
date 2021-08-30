class Solution {
public:

    int bin(vector<int> &arr){
        int left = 0, right = (int)arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid] >= 0){
                left = mid + 1;
            }else
                right = mid - 1;
        }
        return left;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(auto i: grid){
            int temp = bin(i);
            res += abs(temp - (int)i.size());
        }
        return res;
    }
};
