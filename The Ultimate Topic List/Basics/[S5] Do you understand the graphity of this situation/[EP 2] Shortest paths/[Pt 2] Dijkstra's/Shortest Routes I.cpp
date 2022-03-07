#include <bits/stdc++.h>
using namespace std;

#define template_size 100005

using ll = long long;
const ll inf = LLONG_MAX;

ll n, m;

bool visited[template_size];
ll dis[template_size];
using vll = vector<pair<ll, ll>>;
vll graph[template_size];


void dka(){
    using pll = pair<ll, ll>;
    priority_queue<pll, vll, greater<pll>> q;
    q.push({0, 1});
    while (!q.empty()){
        ll u = q.top().second; q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for(auto edge: graph[u]){
            if (dis[edge.first] > dis[u] + edge.second){
                dis[edge.first] = dis[u] + edge.second; q.push({dis[edge.first], edge.first});
            }

        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; i++) cin >> u >> v >> w, graph[u].emplace_back(v, w);
    for(int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    dka();
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    return 0;
}
