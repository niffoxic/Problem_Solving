#include <bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
 
bool solve(ull x, int k){
    while(x){
        if (x % k > 1)
            return false;
        x /= k;
    }
    return true;
}
 
 
int main(){
    int t; cin >> t;
    while(t--){
        ull x, k; cin >> x >> k;
        cout << (solve(x, (int)k)?"YES" : "NO") << "\n";
    }
    return 0;
}
