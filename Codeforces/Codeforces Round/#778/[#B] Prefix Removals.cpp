#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s; cin >> s;
    map<char, int> mp;
    for(auto i: s) mp[i]++;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]--;
        if (!mp[s[i]]){
            cout << s.substr(i) << "\n"; break;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
