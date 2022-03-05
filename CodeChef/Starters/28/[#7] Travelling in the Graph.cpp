#include <bits/stdc++.h>

using namespace std;
#define ll long long

void DFS(ll v, bool visited[], vector<ll> *graph) {
    visited[v] = true;
    for (auto u: graph[v])
        if (!visited[u])
            DFS(u, visited, graph);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    for (ll i = 0, v, u; i < m; i++) cin >> v >> u, adj[v - 1].push_back(u - 1), adj[u - 1].push_back(v - 1);
    bool vis[n];
    memset(vis, false, sizeof(vis));
    DFS(0, vis, adj);
    ll res = 0;
    while (!vis[n - 1]) {
        bool anotherVisited[n];
        memset(anotherVisited, false, sizeof(anotherVisited));
        for (int i = 0; i < n; i++)
            if (vis[i]) {
                if (i + 1 < n)
                    DFS(i + 1, anotherVisited, adj);
                if (i - 1 >= 0)
                    DFS(i - 1, anotherVisited, adj);
            }
        for (int i = 0; i < n; i++)
            vis[i] |= anotherVisited[i];
        res++;
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
