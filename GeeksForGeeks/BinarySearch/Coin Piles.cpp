class Solution {
public:
    int minSteps(int arr[], int n, int k) {
        sort(arr, arr + n);
        int prefix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = arr[i] + prefix[i - 1];

        int res = INT_MAX, previous = 0;
        for (int i = 0; i < n; i++) {
            int frequency = 1;
            while (i + 1 < n && arr[i] == arr[i + 1]) i++, frequency++;
            int thatIndex = upper_bound(arr, arr + n, arr[i] + k) - arr;
            int currentSum = prefix[n - 1] - prefix[thatIndex - 1];
            int neglecting = (n - thatIndex) * (arr[i] + k);
            currentSum -= neglecting;
            res = min(res, currentSum + previous);
            previous += arr[i] * frequency;
        }
        return res;
    }
};

