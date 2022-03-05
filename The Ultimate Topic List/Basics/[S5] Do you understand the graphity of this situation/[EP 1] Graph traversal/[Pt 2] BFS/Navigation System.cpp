#include <bits/stdc++.h>
using namespace std;

#define template_size 200001
vector<int> graph[template_size];
int dis[template_size], counts[template_size],
turns[template_size];


void bfs(int endingAt){
    dis[endingAt] = 1, counts[endingAt] = 0;
    queue<int> q; q.push(endingAt);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for(int u: graph[v]){
            if (!dis[u]){
                dis[u] = dis[v] + 1, q.push(u);
            }else if (dis[u] == dis[v] + 1)
                counts[u]++;
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0, v, u; i < m; i++)
        cin >> u >> v, graph[v].push_back(u);
    int k; cin >> k;
    for(int i = 1; i <= k; i++) cin >> turns[i];
    bfs(turns[k]);
    int left = 0, right = 0;
    for(int i = k; i >= 2; i--){
        if (dis[turns[i]] + 1 != dis[turns[i - 1]])
            left++, right++;
        else if (counts[turns[i - 1]] >= 1) right++;
    }
    return cout << left << " " << right << "\n", 0;
}
