#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int t; cin >> t; mp[t]++;
    }
    bool yea = true;
    for(auto i: mp)
        yea &= ((n + 1) / 2) >= i.second;
    return cout << (yea?"YES":"NO"), 0;
}
