#include <bits/stdc++.h>
using namespace std;

#define template_size 100005
int n, m, cats[template_size], res = 0;
vector<int> graph[template_size];


void dfs(int vertex, int parent, int c){
    if (cats[vertex]) c++;
    else c = 0;
    if (c > m) return;
    if (graph[vertex].size() == 1 && vertex != 1) res++;
    for(auto u: graph[vertex])
        if (u != parent) dfs(u, vertex, c);
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cats[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    return cout << res, 0;
}
