#include <bits/stdc++.h>
using namespace std;


#define template_size 100005
vector<int> friends[template_size];
int cost[template_size];
bool visited[template_size];
int n, m;

int dfs(int v){
    if (visited[v]) return 0;
    int res = cost[v];
    visited[v] = true;
    for(int u: friends[v]) if (!visited[u]) res = min(res, dfs(u));
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 0, u, v; i < m; i++) cin >> u >> v, friends[u].push_back(v),
    friends[v].push_back(u);
    unsigned long long res = 0;
    for(int i = 1; i <= n; i++) res += dfs(i);
    return cout << res, 0;
}
