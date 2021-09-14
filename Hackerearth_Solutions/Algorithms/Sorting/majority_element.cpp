class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val_1 = nums[0], count_1 = 1;
        int val_2 = 0, count_2 = 0;
        int i = 1;

        while(i < nums.size()){
            if (nums[i] == val_1)
                count_1++;
            else if (nums[i] == val_2)
                count_2++;
            else{
                if (count_1 == 0){
                    val_1 = nums[i];
                    count_1 = 1;
                }
                else if (count_2 == 0){
                    val_2 = nums[i];
                    count_2++;
                }else{
                    count_1--;
                    count_2--;
                }
            }
            i++;
        }
        vector<int> res;
        int c1 = 0, c2 = 0;
        for(auto k: nums){
            if (k == val_1) c1++;
            else if (k == val_2) c2++;
        }
        if (c1 > (nums.size() / 3))
            res.push_back(val_1);
        if (val_1 != val_2 && c2 > (nums.size() / 3))
            res.push_back(val_2);

        return res;
    }
};
