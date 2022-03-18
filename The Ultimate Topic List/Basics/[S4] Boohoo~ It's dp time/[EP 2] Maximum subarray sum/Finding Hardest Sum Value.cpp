#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// just take all four direction min subarray sum

void solve(){
    int n, m; cin >> n >> m;
    ll arr[n][m], left[n][m], right[n][m], up[n][m],
    down[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (j == 0) left[i][j] = arr[i][j];
            else left[i][j] = min(arr[i][j], left[i][j - 1] + arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = m - 1; j >= 0; j--){
            if (j == m - 1) right[i][j] = arr[i][j];
            else right[i][j] = min(arr[i][j], arr[i][j] + right[i][j + 1]);
        }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if (i == 0) down[i][j] = arr[i][j];
            else down[i][j] = min(arr[i][j], down[i - 1][j] + arr[i][j]);
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = n - 1; i >= 0; i--){
            if (i == n - 1) up[i][j] = arr[i][j];
            else up[i][j] = min(up[i + 1][j] + arr[i][j], arr[i][j]);
        }
    }
    ll res = 1e18;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) res = min(res, up[i][j] + down[i][j] + left[i][j] + right[i][j] - 3 * arr[i][j]);
    cout << res << "\n";
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
