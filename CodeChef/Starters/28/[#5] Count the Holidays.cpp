#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int res = 8;
        for(int i = 0, a; i < n; i++)
            cin >> a, res += (a + 1) % 7 && a % 7;
        cout << res << "\n";
    }
    return 0;
}
