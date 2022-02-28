#include <bits/stdc++.h>
using namespace std;

bool compi(const pair<int, int>&a, const pair<int, int>&b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}


int main() {
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        unordered_map<long long, int> mp;
        long long total = 0, j;
        for(int i = 0; i < n; i++) cin >> j, mp[j]++, total += j;

        long long max_val = max_element(mp.begin(), mp.end(), compi)->first;
        int freq = max_element(mp.begin(), mp.end(), compi)->second;
        while (q--){
            int temp; cin >> temp;
            if (temp == 1){
                int l; cin >> l;
                total += l, mp[l]++, n++;
                if (mp[l] == freq && max_val > l) max_val = l;
                else if (mp[l] > freq) max_val = l, freq = mp[l];
            }else if (temp == 2) cout << total / n << "\n";
            else cout << max_val << "\n";
        }
    }
    return 0;
}
