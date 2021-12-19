class Solution {
public:

    bool eating(vector<int>& piles, int speed, int h){
        int res = 0;
        for(auto i: piles)
            res += i / speed + ((i % speed)?1:0);
        return res <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        int res = -1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if (eating(piles, mid, h)){
                res = mid;
                right = mid - 1;
            }else
                left = mid + 1;
        }
        return res;
    }
};
