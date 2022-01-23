#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, res = 0; cin >> n;
    unordered_map<long long, long long> mp;
    for(int i = 0; i < n; i++){int t; cin >> t; mp[t]++;}
    for(auto i: mp) res += (i.second * (i.second - 1)) / 2;
    return cout << res, 0;
}
