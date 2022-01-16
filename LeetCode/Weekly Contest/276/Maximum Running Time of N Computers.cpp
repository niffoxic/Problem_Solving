class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 1, right = 0;
        for(auto i: batteries) right += i;

        long long res = 0;
        while (left <= right){
            long long mid = left + ((right - left) >> 1);
            long long screenTime = 0;
            for(auto i: batteries)
                screenTime += (i >= mid? mid: i);
            if (screenTime >= mid * n){
                left = mid + 1, res = mid;
            }else right = mid - 1;
        }
        return res;
    }
};
