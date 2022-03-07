#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
vector<vector<pair<int, int>>> graph;

void dijkstra(int s, vector<int>& dis, vector<int>& parent){
    int n = graph.size();
    dis.assign(n, inf);
    parent.assign(n, -1);

    dis[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, s});
    while (!q.empty()){
        int v = q.top().second;
        int dis_v = q.top().first;
        q.pop();
        if (dis_v != dis[v]) continue;
        for(auto u: graph[v]){
            int to = u.first, len = u.second;
            if(dis[v] + len < dis[to]){
                dis[to] = dis[v] + len;
                parent[to] = v;
                q.push({dis[to], to});
            }
        }
    }
}
