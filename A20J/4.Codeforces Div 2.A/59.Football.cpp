#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    unordered_map<string, int> mp;
    string res;
    while (n--){
        string s; cin >> s;
        mp[s]++;
        if (res.empty()) res += s;
        else if (mp[s] > mp[res])
            res = s;
    }
    cout << res;
    return 0;
}
