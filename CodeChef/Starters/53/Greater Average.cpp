#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        float a, b, c; cin >> a >> b >> c;
        cout << ((((a + b) / 2) > c)? "YES": "NO") << "\n";
    }
    return 0;
}