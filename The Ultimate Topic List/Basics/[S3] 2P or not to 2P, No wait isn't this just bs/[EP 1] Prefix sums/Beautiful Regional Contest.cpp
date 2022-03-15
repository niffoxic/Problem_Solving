#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, int, greater<>> mp;
        for(int i = 0, k; i < n; i++) cin >> k, mp[k]++;
        bool res = false;
        vector<int> same;
        for(auto i: mp) same.push_back(i.second);
        int gold = same[0], silver = 0, bronze = 0;
        int index = 1;
        while (index < same.size() && silver <= gold) silver += same[index++];
        if (gold < silver){
            while (index < same.size() && bronze <= gold) bronze += same[index++];
            while (index < same.size() && gold + silver + bronze + same[index] <= (n >> 1)) bronze += same[index++];
            if (gold + silver + bronze <= (n >> 1)) res = true, cout << gold << " " << silver << " " << bronze << "\n";
        }
        if (!res) cout << "0 0 0" << "\n";
    }
    return 0;
}
