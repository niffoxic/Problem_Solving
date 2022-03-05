#include <bits/stdc++.h>
using namespace std;


#define template_size 300001

int n, k, d;
bool visited[template_size];
vector<pair<int, int>> graph[template_size];
queue<int> q;
set<int> res;
int parent[template_size];

void bfs(){
    while (!q.empty()){
        int v = q.front(); q.pop();
        for(auto u: graph[v]){
            if (parent[v] == u.first) continue;
            else if (!visited[u.first])
                q.push(u.first), visited[u.first] = true,
                parent[u.first] = v;
            else res.insert(u.second);
        }
    }
}

int main(){
    cin >> n >> k >> d;
    for(int i = 0, a; i < k; i++) cin >> a, visited[a] = true;
    for(int i = 1; i <= n; i++) if (visited[i]) q.push(i);
    for(int i = 1, v, u; i < n; i++) cin >> v >> u,
    graph[v].emplace_back(u, i), graph[u].emplace_back(v, i);
    bfs();
    cout << res.size() << "\n";
    for(auto i: res) cout << i << " ";
    return 0;
}
