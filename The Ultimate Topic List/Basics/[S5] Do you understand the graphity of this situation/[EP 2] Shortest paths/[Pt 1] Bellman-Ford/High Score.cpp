#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define template_size 2510
vector<ll> graph[template_size];
bool visited[template_size];

const ll inf = 1e16;

void dfs(ll v){
    visited[v] = true;
    for(ll u: graph[v]) if (!visited[u]) dfs(u);
}

struct edge{
    ll v, u, w;
};

int main() {
    ll n, m; cin >> n >> m;
    vector<edge> edges;
    for(int i = 0, v, u, w; i < m; i++){
        cin >> v >> u >> w;
        edges.push_back({v, u, w});
        graph[v].push_back(u);
    }
    vector<ll> dis(n + 1, -inf);
    dis[1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)
            if (dis[edges[j].v] != -inf && dis[edges[j].u] < dis[edges[j].v] + edges[j].w)
                dis[edges[j].u] = dis[edges[j].v] + edges[j].w;
    }
    for(int i = 0; i < m; i++) if (dis[edges[i].v] != -inf && dis[edges[i].u] < dis[edges[i].v] + edges[i].w) dfs(edges[i].v);
    cout << (!visited[n]? dis[n]: -1);
    return 0;
}
