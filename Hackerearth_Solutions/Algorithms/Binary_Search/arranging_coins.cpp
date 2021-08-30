class Solution {
public:

    long long static nth(long long x){
        if (x % 2)
            return ((x + 1) / 2) * x;
        return (long long)(x / 2) * (x + 1LL);
    }

    int arrangeCoins(int n) {
        long long left = 0, right = 1804289;
        int res = 0;
        while (left <= right){
            long long mid = left + ((right - left) / 2);
            long long current = nth(mid);
            if (current == n){
                return (int)mid;
            }else if (current > n){
                right = mid - 1;
            }else{
                res = (int)mid;
                left = mid + 1;
            }
        }
        return res;
    }
};
