#include <bits/stdc++.h>
using namespace std;

#define template_size 200001
vector<int> graph[template_size];
bool visited[template_size];
vector<int> half[2];

void dfs(int vertex, int side){
    visited[vertex] = true;
    half[side].push_back(vertex);
    for(auto u: graph[vertex])
        if (!visited[u]) dfs(u, side ^ 1);
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 0);
        if (half[0].size() > half[1].size()) swap(half[0], half[1]);
        cout << half[0].size() << "\n";
        for(auto i: half[0]) cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= n; i++) graph[i].clear(), visited[i] = false;
        half[0].clear();
        half[1].clear();
    }
    return 0;
}
