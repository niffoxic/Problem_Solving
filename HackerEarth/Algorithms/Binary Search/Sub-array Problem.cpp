#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long val) {
    if (val <= 3 or val == 5) return true;
    if (val % 2 == 0 or val % 3 == 0 or val % 5 == 0) return false;
    for (int i = 7; i <= sqrt(val); i++)
        if (val % i == 0) return false;
    return true;
}

int main() {
    int n, k; cin >> n >> k;
    vector<long long> arr(n), prefix(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    prefix[0] = isPrime(arr[0]) ? 1 : 0;
    for (int i = 1; i < n; i++)
        prefix[i] = isPrime(arr[i]) ? prefix[i - 1] + 1 : prefix[i - 1];
    long long ans = 0, count;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i]))
            count = lower_bound(prefix.begin(), prefix.end(), prefix[i] + k) - prefix.begin() - i;
        else
            count = lower_bound(prefix.begin(), prefix.end(), prefix[i] + k + 1) - prefix.begin() - i;
        ans += count;
    }
    return cout << ans, 0;
}
