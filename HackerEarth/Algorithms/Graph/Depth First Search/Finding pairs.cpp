#include <bits/stdc++.h>
using namespace std;

#define template_size 100002

vector<int> graph[template_size];
int dis[template_size];
bool visited[template_size];

void dfs(int v){
    visited[v] = true;
    for(int u: graph[v]){
        if (!visited[u]) dis[u] = dis[v] + 1, dfs(u);
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0, u, v; i < n; i++) cin >> u >> v, graph[u].push_back(v),
    graph[v].push_back(u);
    dfs(1);
    long long res = n;
    for(int i = 1; i <= n; i++) res += dis[i];
    return cout << res, 0;
}
