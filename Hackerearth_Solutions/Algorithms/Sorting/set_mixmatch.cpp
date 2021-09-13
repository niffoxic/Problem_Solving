class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int res = 0; for(int i = 1; i <= nums.size(); i++) res ^= i;
        int repeat = 0;
        for(int i = 0; i < nums.size(); i++){
            int current = abs(nums[i]);
            res ^= current;
            if (nums[current - 1] < 0){
                repeat = current;
            }
            nums[current - 1] *= -1;
        }
        cout << repeat << endl;
        return {repeat, res ^ repeat};
    }
};
