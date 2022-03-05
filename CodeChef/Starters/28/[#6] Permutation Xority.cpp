#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n & 1) for(int i = 1; i <= n; i++) cout << i << " ";
        else if (n == 2) cout << -1;
        else{
            cout << "2 3 1 ";
            for(int i = 4; i <= n; i++) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
