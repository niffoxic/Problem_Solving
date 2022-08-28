#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll n; cin >> n;
    ll arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    ll res = 0, take = INT_MAX;
    for (int i = n - 1; i >= 0; i--){
        take = min(take - 1, arr[i]);
        take = max(0LL, take);
        res += take;
    }
    return cout << res, 0;
}
