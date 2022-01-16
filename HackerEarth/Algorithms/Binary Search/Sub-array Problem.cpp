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
    vector<long long> arr(n), primes(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    primes[0] = isPrime(arr[0])?1: 0;
    for (int i = 1; i < n; i++)
        primes[i] = isPrime(arr[i])?primes[i - 1] + 1:primes[i - 1];
    long long ans = 0, count;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i]))
            count = lower_bound(primes.begin(),primes.end(),primes[i] + k) - primes.begin() - i;
        else
            count = lower_bound(primes.begin(),primes.end(),primes[i] + k + 1) - primes.begin() - i;
        ans += count;
    }
    return cout << ans, 0;
}
