#include<bits/stdc++.h>
using namespace std;

#define template_size 200005
vector<int> graph[template_size];
int n, m;
bool visited[template_size], there;


void dfs(int v){
    visited[v] = true;
    if (graph[v].size() != 2) there = false;
    for(int u: graph[v]) if (!visited[u]) dfs(u);
}


int main() {
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, graph[u].push_back(v),
        graph[v].push_back(u);
    int res = 0;
    for(int i = 1; i <= n; i++){
        if (!visited[i]){
            there = true;
            dfs(i);
            res += there;
        }
    }
    return cout << res, 0;
}
