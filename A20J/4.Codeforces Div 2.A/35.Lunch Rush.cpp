#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(){
    ll n, k, res{INT_MIN}; cin >> n >> k;
    while (n--){
        ll f, t; cin >> f >> t;
        res = max(res, (t > k? f - (t - k): f));
    }
    cout << res;
    return 0;
}
