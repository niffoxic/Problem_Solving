class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long res[3] = {LONG_LONG_MIN, LONG_LONG_MIN, LONG_LONG_MIN};
       for(auto i: nums){
           if (res[0] < i){
               res[2] = res[1];
               res[1] = res[0];
               res[0] = i;
           }else if (res[0] != i && res[1] < i){
               res[2] = res[1];
               res[1] = i;
           }else if (res[0] != i && res[1] != i && res[2] < i){
               res[2] = i;
           }
       }
        return res[2] == LONG_LONG_MIN?res[0]:res[2];
    }
};
