#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int n = s.size();
        int res = n;
        int pointers[3]; pointers[0] = pointers[1] = pointers[2] = -n;
        for(int i = 0; i < n; i++){
            pointers[s[i] - '1'] = i;
            res = min(res, i - min(pointers[0], min(pointers[1], pointers[2])));
        }
        if (res == n) cout << 0 << "\n";
        else cout << res + 1 << "\n";
    }
    return 0;
}
