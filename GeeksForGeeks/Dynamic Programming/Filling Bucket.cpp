class Solution {
public:
    int fillingBucket(int n) {
        if (n <= 2) return n;
        int mod = 100000000;
        int left = 1, right = 2, index = 2, t = -1;
        while (index < n) t = right, right = (left + right) % mod, left = t, index++;
        return right;
    }
};
