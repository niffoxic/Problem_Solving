#include <bits/stdc++.h>
using namespace std;

#define template_size 2505

using ll = long long;

const ll inf = INT_MAX - 1000;

struct edge{
    ll u, v, w;
};
vector<edge> graph;
ll dis[template_size];
ll parent[template_size];

void bellman(int n, int m, int s){
    for(int i = 0; i < template_size; i++) dis[i] = inf;
    dis[s] = 0;
    ll there;
    for(int i = 0; i < n; i++){
        there = 0;
        for(int j = 0; j < m; j++){
            if (dis[graph[j].v] > dis[graph[j].u] + graph[j].w){
                dis[graph[j].v] = dis[graph[j].u] + graph[j].w;
                parent[graph[j].v] = graph[j].u;
                there = graph[j].v;
            }
        }
    }
    if (!there){
        cout << "NO"; return;
    }
    cout << "YES\n";
    vector<ll> path;
    for(ll i = 1; i <= n; i++) there = parent[there];
    for(ll i = there;; i = parent[i]){
        path.push_back(i);
        if (i == there && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());
    for(auto i: path) cout << i << " ";
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0, u, v, w; i < m; i++) cin >> u >> v >> w,
        graph.push_back({u, v, w});
    bellman(n, m, 1);
    return 0;
}
