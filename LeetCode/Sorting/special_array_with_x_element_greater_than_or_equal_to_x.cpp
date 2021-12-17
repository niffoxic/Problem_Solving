class Solution {
private:
    int countGreaterOrEqual(vector<int> &nums, int val){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums.at(mid) <  val) left  = mid + 1;
            else if(nums.at(mid) >= val) right = mid - 1;
        }
        return nums.size() - left;
    }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back();        
        for(int i = 1; i <= maxVal; i++)
            if(countGreaterOrEqual(nums, i) == i) return i;
        return -1;
    }
};
