void dijkstra(int s, vector<int>& dis, vector<int>& parent){
    int n = graph.size();
    dis.assign(n, inf);
    parent.assign(n, -1);

    dis[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto u: graph[v]){
            int to = u.first;
            int len = u.second;
            if (dis[v] + len < dis[to]){
                q.erase({dis[to], to});
                dis[to] = dis[v] + len;
                parent[to] = v;
                q.insert({dis[to], to});
            }
        }
    }
}
