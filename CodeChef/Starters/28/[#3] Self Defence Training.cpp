#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int res = 0;
        for(int i = 0, a; i < n; i++)
            cin >> a, res += a >= 10 && a <= 60? 1: 0;
        cout << res << "\n";
    }
    return 0;
}
