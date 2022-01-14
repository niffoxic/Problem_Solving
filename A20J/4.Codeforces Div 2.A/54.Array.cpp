#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> pos, nev, zero, res[4];
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t > 0) pos.push_back(t);
        else if (t < 0) nev.push_back(t);
        else zero.push_back(t);
    }

    if (!pos.empty()){
        res[1].push_back(pos.back());
        pos.pop_back();
    }else{
        res[1].push_back(nev.back());
        nev.pop_back();
        res[1].push_back(nev.back());
        nev.pop_back();
    }
    res[0].push_back(nev.back()); nev.pop_back();
    for(auto i: nev) res[2].push_back(i);
    for(auto i: pos) res[2].push_back(i);
    for(auto i: zero) res[2].push_back(i);

    for (int i = 0; i <= 2; ++i) {
        cout << res[i].size() << " ";
        for(auto j: res[i]) cout << j << " ";
        cout << "\n";
    }
    return 0;
}
