#include <bits/stdc++.h>
using namespace std;

#define template_size 100005
using ll = long long;

ll n, m;
using pi = pair<ll, ll>;
vector<pi> graph[template_size];
ll dis[template_size], parent[template_size];
bool present[template_size];


void res(ll x){
    if (x != 1) res(parent[x]);
    cout << x << " ";
}


void dijkstra(){
    priority_queue<ll> q; q.push(1);
    while (!q.empty()){
        ll u = q.top(); q.pop();
        present[u] = false;
        for(auto edge: graph[u]){
            ll v = edge.first, w = edge.second;
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                parent[v] = u;
                if (!present[v]) present[v] = true, q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; i++)
        cin >> u >> v >> w,
                graph[u].emplace_back(v, w),
                graph[v].emplace_back(u, w);
    fill(dis + 2, dis + n + 1, 1e18);
    dijkstra();
    if (dis[n] == (ll)1e18) cout << -1;
    else res(n);
    return 0;
}
