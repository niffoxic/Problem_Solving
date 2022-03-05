#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[3002];
bool visited[3002], found = false;
int parent[3002], dis[3002];
pair<int, int> cords;
queue<int> q;


void dfs(int v = 1, int par = 0){
    visited[v] = true;
    for(int u: graph[v]){
        if (!visited[u])
            parent[u] = v, dfs(u, v);
        else if (u != par && !found) found = true,
        parent[u] = v, cords = {v, u};
    }
}

void bfs(){
    while (!q.empty()){
        int v = q.front(); q.pop();
        for(int u: graph[v]){
            if (!visited[u])
                visited[u] = true,
                dis[u] = dis[v] + 1,
                q.push(u);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0, v, u; i < n; i++)
        cin >> v >> u, graph[v].push_back(u),
        graph[u].push_back(v);
    dfs();
    for(int i = 0; i < 3002; i++) visited[i] = false;
    for(int v = cords.first; v != cords.second; v = parent[v])
        q.push(v), visited[v] = true;
    q.push(cords.second);
    visited[cords.second] = true;
    bfs();
    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}
