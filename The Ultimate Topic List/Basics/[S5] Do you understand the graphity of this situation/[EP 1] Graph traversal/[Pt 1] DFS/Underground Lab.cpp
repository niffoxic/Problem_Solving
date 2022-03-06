#include <bits/stdc++.h>
using namespace std;

#define template_size 200001
vector<int> graph[template_size], res;
bool visited[template_size];

void dfs(int u){
    visited[u] = true;
    res.push_back(u);
    for(int v: graph[u]){
        if (!visited[v]) dfs(v), res.push_back(u);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1, v, u; i <= m; i++) cin >> v >> u, graph[v].push_back(u),
    graph[u].push_back(v);
    dfs(1);
    int ans = 0;
    for(int i = 1; i <= k; i++){
        int current = (res.size() - ans + k - i) / (k - i + 1);
        cout << current << " ";
        for(int j = ans; j < ans + current; j++)
            cout << res[j] << " ";
        puts("");
        ans += current;
    }
    return 0;
}
