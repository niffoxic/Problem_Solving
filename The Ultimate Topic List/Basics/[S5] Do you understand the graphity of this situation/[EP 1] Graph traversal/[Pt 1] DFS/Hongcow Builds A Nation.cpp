#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define template_size 1010

int connected, n, m, k;
bool visited[template_size];
int location[template_size];
vector<int> graph[template_size];

void dfs(int x) {
    visited[x] = true; connected++;
    for (int i : graph[x]) if (!visited[i]) dfs(i);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> location[i];
    vector<int> res;
    int edges = n;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, graph[u].pb(v), graph[v].pb(u);
    for (int i = 0; i < k; i++) {
        connected = 0;
        dfs(location[i]);
        res.pb(connected);
        edges -= connected;
    }
    sort(res.rbegin(), res.rend());
    res[0] += edges;
    ll ans = 0;
    for (int i = 0; i < k; i++) ans += 1ll * res[i] * (res[i] - 1) / 2ll;
    return cout << ans - m, 0;
}
