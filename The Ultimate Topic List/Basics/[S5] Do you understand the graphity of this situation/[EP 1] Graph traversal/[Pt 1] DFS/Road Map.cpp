#include <bits/stdc++.h>
using namespace std;

#define template_size 50010

int n, r1, r2, p[template_size];
vector <int> graph[template_size];

void dfs(int u, int parent=0) {
    p[u] = parent;
    for (int v : graph[u]) if (v != parent) dfs(v, u);
}

int main() {
    cin >> n >> r1 >> r2;
    for (int i = 1, v; i <= n; i ++) if (i != r1) cin >> v, graph[i].push_back(v), graph[v].push_back(i);
    dfs(r2);
    for (int i = 1; i <= n; i ++) if (i != r2) cout << p[i] << " ";
    return 0;
}
