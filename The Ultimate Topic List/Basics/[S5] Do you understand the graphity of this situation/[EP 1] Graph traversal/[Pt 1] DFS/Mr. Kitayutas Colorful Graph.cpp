#include <bits/stdc++.h>
using namespace std;

#define template_size 250

vector<int> graph[template_size][template_size];
bool visited[template_size];

bool dfs(int u, int v, int color){
    visited[u] = true;
    bool connected = false;
    for(int con: graph[color][u]){
        if (con == v) return true;
        if (!visited[con]) connected = connected || dfs(con, v, color);
    }
    return connected;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0, u, v, c; i < m; i++) cin >> u >> v >> c,
    graph[c][u].push_back(v), graph[c][v].push_back(u);
    int q; cin >> q;
    while (q--){
        int u, v; cin >> u >> v;
        int res = 0;
        for(int i = 1; i <= m; i++){
            res += dfs(u, v, i);
            memset(visited, false, template_size);
        }
        cout << res << "\n";
    }
}
