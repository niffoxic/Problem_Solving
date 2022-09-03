#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;


int main(){
    int t; cin >> t;
    while(t--){
        ull n; cin >> n;
        ull left = n >> 1, right = (n >> 1) + (n & 1);
        cout << (1ULL * left * right * 2) << "\n";
    }
    return 0;
}