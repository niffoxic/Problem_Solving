#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if (!x && !y) cout << 0 << "\n";
        else{
            float val = x * x + y * y;
            float sq = sqrt(val);
            if ((int)sq == sq) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
    return 0;
}
