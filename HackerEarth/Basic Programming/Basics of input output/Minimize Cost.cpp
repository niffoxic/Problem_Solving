#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, k; cin >> n >> k;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0, j = 0; i < n; i++){
        if (arr[i] < 0) continue;
        while (i - j > k) j++;
        while (arr[i] && (i + k) >= min(n - 1, j)){
            if (arr[j] > 0){ j++; continue; }
            int mini = min(arr[i], abs(arr[j]));
            arr[i] -= mini, arr[j] += mini;
            if (arr[j] >= 0) j++;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++) res += abs(arr[i]);
    return cout << res, 0;
}

