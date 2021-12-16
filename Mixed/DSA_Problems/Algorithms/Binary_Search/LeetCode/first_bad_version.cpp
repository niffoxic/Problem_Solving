class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = INT_MAX, mid;
        int res = 0;
        while(left < right){
            mid = left + (right - left) / 2;
            if(mid > 0 && isBadVersion(mid) && !isBadVersion(mid - 1)) return mid;
            else if (!isBadVersion(mid)){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res + 1;
    }
};
