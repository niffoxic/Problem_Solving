#include <bits/stdc++.h>
using namespace std;

#define temp_size 100005
using ll = long long;
ll arr[temp_size], prefix[temp_size], ki;
int n, q;

int lower(){
    int left = 1, right = n;
    while (left < right){
        int mid = left + ((right - left) >> 1);
        if (arr[mid] < ki) left = mid + 1;
        else right = mid;
    }
    return right;
}


void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i];
    while (q--){
        cin >> ki;
        int right = lower();
        if (arr[right] >= ki) right--;
        int secured = right, left = min(1, right);
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (1LL * ki * (secured - mid) - prefix[secured] + prefix[mid] <= mid)
                right = mid;
            else left = mid + 1;
        }
        cout << n - left << "\n";
    }
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
