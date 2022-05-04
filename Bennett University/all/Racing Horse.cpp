#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        ll res = LLONG_MAX;
        for(int i = 1; i < n; i++) res = min(res, arr[i] - arr[i - 1]);
        cout << res << "\n";
    }
    return 0;
}
