#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            res = min(k, res);
        }
        cout << res << "\n";
    }
}
