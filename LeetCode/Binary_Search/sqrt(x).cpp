class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long  left = 1, right = 214739559900;
        int res = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if (mid == x / mid)
                return (int)mid;
            else if (mid > x / mid){
                right = mid - 1;
            }
            else{
                left = mid + 1;
                res = (int)mid;
            }
        }
        return res;
    }
};
