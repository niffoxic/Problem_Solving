class Solution {
public:
    bool continueRace(long n, long m, long l, const long bike[], const long a[], long hour) {
        long summation = 0;
        for (int i = 0; i < n; i++) {
            long speed = bike[i] + a[i] * hour;
            if (speed >= l)
                summation += speed;
        }
        return summation < m;
    }


    long buzzTime(long N, long M, long L, long H[], long A[]) {
        long left = 1, right = M, res = -1;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (continueRace(N, M, L, H, A, mid)) {
                res = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return res + 1;
    }
};
