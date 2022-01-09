#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, c, p; cin >> n >> c >> p;
    int res = 0;
    for(int i = 1; i < n; i++){
        int t; cin >> t;
        res = max(res, p - t - c);p = t;
    }
     cout << res;
    return 0;
}
