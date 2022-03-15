#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    vector<ll> can(n); for(int i = 0; i < n; i++) cin >> can[i];
    sort(can.begin(), can.end());
    vector<ll> res(n, 0);
    ll cum = 0;
    for(int i = 0; i < n; i++){
        cum += can[i];
        res[i] = cum;
        if (i >= m) res[i] += res[i - m];
        cout << res[i] << " ";
    }
    return 0;
}
