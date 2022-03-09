#include <bits/stdc++.h>
using namespace std;


#define template_size 50
int n, m, friends;
vector<int> graph[template_size];
bool visited[template_size];
int records[template_size];
vector<pair<int, int>> pairs;
vector<int> singles;
vector<pair<int, pair<int, int>>> res;

void dfs(int v){
    visited[v] = true;
    records[friends] = v; friends++;
    for(int u: graph[v]) if (!visited[u]) dfs(u);
}


int main(){
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, graph[u].push_back(v),
        graph[v].push_back(u);

    for(int i = 1; i <= n; i++){
        if (visited[i]) continue;
        friends = 0;
        dfs(i);
        if (friends > 3) return cout << -1, 0;
        if (friends == 2) pairs.emplace_back(records[0], records[1]);
        else if (friends == 1) singles.push_back(records[0]);
        else res.push_back({records[0], {records[1], records[2]}});
    }

    if (pairs.size() > singles.size()) return cout << -1, 0;
    for(int i = 0; i < pairs.size(); i++) res.emplace_back(singles[i], pairs[i]);
    for(int i = (int)pairs.size(); i < singles.size(); i += 3)
        res.push_back({singles[i], {singles[i + 1], singles[i + 2]}});

    for(auto & i : res) cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    return 0;
}
