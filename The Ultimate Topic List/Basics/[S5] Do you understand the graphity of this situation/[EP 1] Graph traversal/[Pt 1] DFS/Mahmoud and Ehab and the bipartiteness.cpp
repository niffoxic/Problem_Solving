#include <bits/stdc++.h>
using namespace std;

#define template_size 100005
int n;
vector<int> graph[template_size];
int bi[2];

void dfs(int v, int parent, int side){
    bi[side]++;
    for(int u: graph[v]) if (u != parent) dfs(u, v, side ^ 1);
}


int main(){
    cin >> n;
    for(int i = 1, u, v; i < n; i++) cin >> u >> v, graph[u].push_back(v),
    graph[v].push_back(u);
    dfs(1, 0, 0);
    return cout << (long long)bi[0] * bi[1] - n + 1LL, 0;
}
