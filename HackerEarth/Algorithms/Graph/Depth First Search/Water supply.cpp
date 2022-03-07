#include <bits/stdc++.h>
using namespace std;

#define template_size 1000005

int n, current = 1, res = 0;
vector<int> graph[template_size];
int allowed[template_size];
bool visited[template_size];

void dfs(int v){
    visited[v] = true;
    for(int u : graph[v]){
        if (!visited[u]){
            current++;
            if (allowed[u] && !allowed[u - 1]) return;
            if (allowed[u] && allowed[u - 1]){
                current--; return;
            }
            dfs(u);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1, u, v; i < n; i++) cin >> u >> v, graph[u].push_back(v),
    graph[v].push_back(u);
    for(int i = 1; i <= n; i++) cin >> allowed[i];
    for(int i = 1; i <= n; i++){
        if (!visited[i]){
            current = 1; dfs(i); res = max(res, current);
        }
    }
    cout << res << "\n";
    return 0;
}
