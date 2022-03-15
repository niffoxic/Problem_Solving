#include <bits/stdc++.h>

using namespace std;

vector<int> pos[26];

int main() {
    int n, m; string s, t; cin >> n >> s >> m;
    for(int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
    while (m--){
        cin >> t;
        int res = 0, fq[26] = {};
        for(auto i: t) fq[i - 'a']++;
        for(int i = 0; i < 26; i++) if (fq[i]--) res = max(res, pos[i][fq[i]]);
        cout << ++res << "\n";
    }
}
