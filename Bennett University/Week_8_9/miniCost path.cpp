#include <bits/stdc++.h>
using namespace std;

#define N 100005
using ll = long long;

ll n, m, s;
using pll = pair<ll, ll>;
vector<pll> g[N];
ll res[N], cost[N];
bool present[N];
queue<int> que;



void solve(){
    res[s] = 0;
    que.push(s);
    while (!que.empty()){
        int u = que.front(); que.pop();
        present[u] = false;
        for(auto node: g[u]){
            int v = node.first, w = node.second;
            if (res[u] + w + cost[v] < res[v]){
                res[v] = res[u] + w + cost[v];
                if (!present[v]) present[v] = true, que.push(v);
            }
        }
    }
}

int main() {

    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 0, u, v, w; i < m; i++)
        cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    fill(res + 1, res + n + 1, 1e18);
    solve();
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    return 0;
}
