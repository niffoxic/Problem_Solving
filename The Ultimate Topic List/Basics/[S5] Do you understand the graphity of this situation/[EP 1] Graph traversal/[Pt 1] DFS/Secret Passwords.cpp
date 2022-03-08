#include <bits/stdc++.h>
using namespace std;

#define template_size 2000005

vector<int> graph[template_size];
bool visited[template_size];

void dfs(int v){
    visited[v] = true;
    for(int u: graph[v]) if (!visited[u]) dfs(u);
}


int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(auto c: s) graph[n + c - 'a'].push_back(i),
        graph[i].push_back(n + c - 'a');
    }
    int res = 0;
    for(int i = n; i < n + 26; i++) if (!visited[i] && !graph[i].empty()) res++, dfs(i);
    return cout << res, 0;
}
