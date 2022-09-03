#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int w, x, y, z; cin >> w >> x >> y >> z;
        int res = 0;
        if (w == x || w == y || w == z) res = 1;
        else if (w == x + y || w == x + z || w == y + z || w == x + y + z) res = 1;
        cout << (res?"YES": "NO") << "\n";
    }
    return 0;
}