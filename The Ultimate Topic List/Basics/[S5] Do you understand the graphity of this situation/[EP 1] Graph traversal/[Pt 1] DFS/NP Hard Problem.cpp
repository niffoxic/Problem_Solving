#include <bits/stdc++.h>
using namespace std;

#define template_size 100001

int n, m;
vector<int> graph[template_size];
vector<int> bipartite[2];
int coloured[template_size];

bool dfs(int vertex, int color){
    coloured[vertex] = color;
    bipartite[color - 1].push_back(vertex);
    for(auto u: graph[vertex]){
        if (!coloured[u] && dfs(u, 3 - color)) return true;
        if (coloured[u] != 3 - color) return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if (!coloured[i]){
            if (!graph[i].size()) continue;
            if (dfs(i, 2)) return cout << -1, 0;
        }
    }
    for(auto & i : bipartite){
        cout << i.size() << "\n";
        for(auto u: i) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
