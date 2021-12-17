class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 || (n & (n - 1)))
            return false;
        int bits = 0;
        while (n > 0){
            bits++;
            n >>= 1;
        }
        bits--;
        return !(bits % 2);
    }
};
