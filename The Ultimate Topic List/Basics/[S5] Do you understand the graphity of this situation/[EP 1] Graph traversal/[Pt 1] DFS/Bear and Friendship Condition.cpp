#include <bits/stdc++.h>
using namespace std;

#define template_size 150010
using ll = long long;
ll n, m;
vector<ll> graph[template_size];
bool visited[template_size];
ll edges, vertexes;

void dfs(ll v){
    vertexes++;
    visited[v] = true;
    for(ll u: graph[v]){
        edges++;
        if (!visited[u]) dfs(u);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, graph[u].push_back(v),
        graph[v].push_back(u);
    for(int i = 1; i <= n; i++){
        if (!visited[i]){
            edges = 0, vertexes = 0;
            dfs(i);
            if (edges != vertexes * (vertexes - 1)) return cout << "NO", 0;
        }
    }
    return cout << "YES", 0;
}
