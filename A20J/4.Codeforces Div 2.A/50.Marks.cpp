#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    string s[n];
    vector<char> v(m, 0);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            v[j] = max(v[j], s[i][j]);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (v[j] == s[i][j]){
                res++; break;
            }
        }
    }
    return cout << res, 0;
}
