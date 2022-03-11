#include <bits/stdc++.h>
using namespace std;

#define template_size 100005
int dis[template_size];
bool present[template_size];
queue<int> q;
vector<pair<int, int>> graph[template_size];
vector<tuple<int, int, int>> onRoad;
int n, m, s, l;


void dka(){
    dis[s] = 0;
    q.push(s);
    while (!q.empty()){
        int u = q.front(); q.pop();
        present[u] = false;
        for(auto [v, w]: graph[u]){
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                if (!present[v]) present[v] = true, q.push(v);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> s;
    for(int i = 0, u, v, w; i < m; i++) cin >> u >> v >> w,
    graph[u].emplace_back(v, w), graph[v].emplace_back(u, w),
    onRoad.emplace_back(u, v, w);
    cin >> l;
    fill(dis + 1, dis + n + 1, 1e9);
    dka();
    int res = 0;
    for(int i = 1; i <= n; i++) if (dis[i] == l) res++;
    for(auto [u, v, w]: onRoad){
        if (dis[u] < l && dis[u] + w > l && (dis[u] + w) - l + dis[v] > l) res++;
        if (dis[v] < l && dis[v] + w > l && (dis[v] + w) - l + dis[u] > l) res++;
        if (dis[v] < l && dis[u] < l && dis[u] + dis[v] + w == 2 * l) res++;
    }
    return cout << res, 0;
}
