class Solution {
public:

    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c) + 1;
        while (left <= right){
            long long val = left * left + right * right;
            cout << val << "\n";
            if (val == c)
                return true;
            else if (val > c)
                right--;
            else left++;
        }
        return false;
    }
};
