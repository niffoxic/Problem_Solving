#include <bits/stdc++.h>
using namespace std;

vector<int> matrix[200001];
bool visited[10001];

void dfs(int i){
    visited[i] = true;
    for(auto u: matrix[i]) if (!visited[u]) dfs(u);
}


int main(){
    int n, m, there = 0; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t; cin >> t; there += t;
        for(int j = 0; j < t; j++){
            int temp; cin >> temp;
            matrix[i + m].push_back(temp - 1);
            matrix[temp - 1].push_back(i + m);
        }
    }
    if (!there) return cout << n, 0;
    there = 0;
    for(int i = m; i < m + n; i++)
        if (!visited[i]) dfs(i), there++;
    return cout << there - 1, 0;
}
