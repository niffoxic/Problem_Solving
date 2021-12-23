class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto x = nums.begin();
        while (x != nums.end()){
            if (*x == val){
                nums.erase(x);
                x = nums.begin();
            }else
                x++;
        }
        return nums.size();
    }
};
