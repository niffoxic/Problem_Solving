#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> graph;
vector<int> gender;
bool res = false;

void dfs(int vertex, int sex){
    if (res) return;
    gender[vertex] = sex;
    for(int i = 0; i < graph[vertex].size(); i++){
        if (gender[graph[vertex][i]] == -1) dfs(graph[vertex][i], 1 - sex);
        else if (gender[graph[vertex][i]] == gender[vertex]){
            res = true; return;
        }
    }
}

void solve(int case_no){
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    gender.assign(n + 1, -1);
    res = false;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if (gender[i] == -1) dfs(i, 0);
    cout << "Scenario #" << case_no << ":\n";
    cout << (!res? "No suspicious bugs found!": "Suspicious bugs found!");
    cout << "\n";
}

int main(){
    int test_cases; cin >> test_cases;
    for(int i = 1; i <= test_cases; i++) solve(i);
    return 0;
}
