#include <bits/stdc++.h>
using namespace std;

#define template_size 105

using pii = pair<int, int>;
vector<pii> graph[template_size];
bool visited[template_size];

int dfs(int u){
    int res = 0;
    visited[u] = true;
    for(pii v: graph[u]) if (!visited[v.first]) res = max(res, v.second + dfs(v.first));
    return res;
}

int main(){
    int n; cin >> n;
    for(int i = 1, u, v, c; i < n; i++) cin >> u >> v >> c,
    graph[u].emplace_back(v, c), graph[v].emplace_back(u, c);
    return cout << dfs(0), 0;
}
