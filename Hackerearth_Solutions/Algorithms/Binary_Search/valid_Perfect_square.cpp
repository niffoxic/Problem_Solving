class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  left = 0, right = num;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if (mid * mid == num) return true;
            else if (mid * mid > num) right = mid - 1LL;
            else left = mid + 1LL;
        }
        return false;
    }
};
