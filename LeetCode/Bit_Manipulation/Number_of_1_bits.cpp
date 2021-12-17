class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0){
            res = (n & 1)? res + 1: res;
            n >>= 1;
        }
        return res;
    }
};
