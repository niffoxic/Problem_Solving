#include <bits/stdc++.h>
using namespace std;


using ld = long double;

#define template_size 100001
int n;
vector<int> graph[template_size];

ld dfs(int vertex, int parent){
    ld sum = 0;
    for(auto u: graph[vertex])
        if (u != parent)
            sum += dfs(u, vertex) + 1;
    return sum > 0? sum / (graph[vertex].size() - (parent != -1)): 0;
}


int main(){
    cin >> n;
    for(int  i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    return cout << fixed << setprecision(7) << dfs(0, -1), 0;
}
