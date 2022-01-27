#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        unordered_map<ll, ll> mp;
        ll n, k; cin >> n >> k;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            mp[c]+=c;
        }
        vector<ll>res;
        for(auto i: mp){
            if (i.second > 0)
                res.push_back(i.second);
        }
        sort(res.begin(), res.end(), greater<>());
        ll ans = 0;
        for(int i = 0; i < min(k, (ll)(res.size())); i++)
            ans += res[i];
        cout << ans << "\n";
    }

    return 0;
}
