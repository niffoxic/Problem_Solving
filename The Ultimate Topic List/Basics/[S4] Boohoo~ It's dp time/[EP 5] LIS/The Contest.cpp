#include <bits/stdc++.h>
using namespace std;

#define template_size 200002
using ll = long long;
ll arr[template_size], k1, k2, k3;


int main(){
    cin >> k1 >> k2 >> k3;
    ll n = k1 + k2 + k3;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + k1 + 1);
    sort(arr + 1 + k1, arr + k1 + 1 + k2);
    sort(arr + 1 + k1 + k2, arr + k1 + 1 + k2 + k3);
    vector<ll> dp;
    vector<ll>::iterator iter;
    for(int i = 1; i <= n; i++){
        iter = upper_bound(dp.begin(), dp.end(), arr[i]);
        if (iter == dp.end()) dp.push_back(arr[i]);
        else *iter = arr[i];
    }
    return cout << n - dp.size(), 0;
}
