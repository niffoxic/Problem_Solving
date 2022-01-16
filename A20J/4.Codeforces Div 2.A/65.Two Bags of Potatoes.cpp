#include <bits/stdc++.h>
using namespace std;


int main(){
    int y, k, n; cin >> y >> k >> n;
    int res = 0;
    for(int i = k - y; i <= n - y; i+= k)
        if (i > 0){
            cout << i << " ";
            res = 1;
        }
    if (!res) cout << -1;
    return 0;
}
