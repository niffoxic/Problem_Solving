#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        unordered_map<long long, long long> mp;
        long long n, k; cin >> n >> k;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            mp[c]+=c;
        }
        vector<long long>res;
        for(auto i: mp){
            if (i.second > 0)
                res.push_back(i.second);
        }
        sort(res.begin(), res.end(), greater<>());
        long long ans = 0;
        for(int i = 0; i < min(k, (long long)(res.size())); i++)
            ans += res[i];
        cout << ans << "\n";
    }

    return 0;
}
