#include<bits/stdc++.h>
using namespace std;


using ll = long long;
const int N = 2e4 + 1;
ll x[N], v[N], id[N], res[N];

int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        iota(id, id + n, 0);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        for(int i = 0; i < n; i++)
            cin >> v[i];

        vector<pair<int, int>> changes;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (x[i] < x[j] && v[i] > 0 && v[j] < 0)
                    changes.emplace_back(i, j);
        sort(changes.begin(), changes.end(), [](pair<int, int>&a, pair<int, int>&b){
            return (x[a.second] - x[a.first]) * (v[b.first] - v[b.second]) <
                    (x[b.second] - x[b.first]) * (v[a.first] - v[a.second]);
        });
        fill(res, res + n, 0);
        for(auto i: changes){
            ll current = (x[i.second] - x[i.first]) / (v[i.first] - v[i.second]);
            res[id[i.first]] += current;
            res[id[i.second]] += current;
            swap(id[i.first], id[i.second]);
        }
        for (int i = 0; i < n; ++i)
            cout << res[i] << "\n";
    }

    return 0;
}
