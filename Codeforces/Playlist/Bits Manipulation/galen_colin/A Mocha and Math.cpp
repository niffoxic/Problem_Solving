#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int t; cin >> t;
    while (t--){
        int res, n; cin >> n;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            if (i == 0) res = k;
            res &= k;
        }
        cout << res << "\n";
    }
}
