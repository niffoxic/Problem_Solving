#include <bits/stdc++.h>
using namespace std;


#define template_size 110
int n, m, connected;
vector<int> graph[template_size];
bool visited[template_size];


void dfs(int v){
    visited[v] = true;
    connected++;
    for(int u: graph[v]) if (!visited[u]) dfs(u);
}


int main(){
    cin >> n >> m;
    if (n != m) return cout << "NO", 0;
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, graph[u].push_back(v),
        graph[v].push_back(u);
    dfs(1);
    return cout << (connected == n? "FHTAGN!": "NO"), 0;
}
