#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    vector<ll> dp;
    vector<ll> :: iterator iter;
    ll n, val;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        val -= i;
        if (val <= 0) continue;
        iter = upper_bound(dp.begin(), dp.end(), val);
        if (iter == dp.end()) dp.push_back(val);
        else *iter = val;
    }
    return cout << n - dp.size(), 0;
}
