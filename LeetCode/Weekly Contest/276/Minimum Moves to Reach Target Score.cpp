class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target > 1){
            if (!(target % 2) && maxDoubles){
                target /= 2;
                maxDoubles--;
            }else
                target--;
            res++;
            if (!maxDoubles) break;
        }
        return res + (target - 1);
    }
};
