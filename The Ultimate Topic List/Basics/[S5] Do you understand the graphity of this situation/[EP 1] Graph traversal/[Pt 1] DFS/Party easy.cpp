#include <bits/stdc++.h>

using namespace std;

int n, m, res, counts, conflict, visited[2005];
vector<int> friends[2005], dislike[2005];

void dfs(int v, int root) {
    visited[v] = root;
    counts++;
    for (auto u:friends[v]) if (!visited[u]) dfs(u, root);
    for (auto u:dislike[v]) if (visited[u] == visited[v]) conflict = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) cin >> x >> y, friends[x].push_back(y), friends[y].push_back(x);
    cin >> m;
    for (int i = 0, x, y; i < m; i++) cin >> x >> y, dislike[x].push_back(y), dislike[y].push_back(x);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) {
            counts = 0, conflict = 1;
            dfs(i, i);
            if (conflict) res = max(counts, res);
        }
    return cout << res, 0;
}
