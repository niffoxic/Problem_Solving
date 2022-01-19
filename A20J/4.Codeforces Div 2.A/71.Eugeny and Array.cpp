#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
 
    int n, m; cin >> n >> m;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if (t == 1) a++;
        else b++;
    }
    int maxi = min(a, b) * 2;
    while (m--){
        int l, r; cin >> l >> r;
        int sub = r - l + 1;
        if (sub % 2 == 1 || sub > maxi) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
