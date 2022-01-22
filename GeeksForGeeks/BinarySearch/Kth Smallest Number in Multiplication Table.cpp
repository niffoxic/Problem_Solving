class Solution {
public:
    bool within(int m, int n, int k, int limit) {
        int res = 0;
        for (int i = 1; i <= m; i++) {
            if (limit >= i * n)
                res += n;
            else res += limit / i;
        }
        return res < k;
    }


    int KthSmallest(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (within(m, n, k, mid)) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
