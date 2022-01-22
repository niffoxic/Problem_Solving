class Solution {
public:
    bool boating(const int arr[], int n, int d, int weight) {
        int current = 0, day = 1;
        for (int i = 0; i < n; i++) {
            current += arr[i];
            if (current > weight) {
                current = arr[i];
                day++;
                if (day > d) return false;
            }
        }
        return day <= d;
    }


    int leastWeightCapacity(int arr[], int N, int D) {
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < N; i++) {
            left = max(left, arr[i]);
            right += arr[i];
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (boating(arr, N, D, mid)) {
                res = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return res;
    }
};
