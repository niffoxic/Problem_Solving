// No idea why


#include <bits/stdc++.h>
using namespace std;

#define template_size 1000005


int main(){
    int n, x; cin >> n >> x;
    int res = 1;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if (x >= t) res++, x -= t;
        else x = -1;
    }
    cout << res;
    return 0;
}
