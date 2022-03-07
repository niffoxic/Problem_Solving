const int inf = 1 << 30;
vector<vector<pair<int, int>>> graph;

void dijkstra(int s, vector<int>& dis, vector<int>& parent){
    int n = graph.size();
    dis.assign(n, inf);
    parent.assign(n, -1);
    vector<bool> visited(n, false);
    dis[s] = 0;
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++) if (!visited[j] && (v == -1 || dis[j] < dis[v]))
            v = j;
        if (dis[v] == inf) break;
        visited[v] = true;
        for(auto u: graph[v]){
            int to = u.first;
            int len = u.second;
            if (dis[v] + len < dis[to]){
                dis[to] = dis[v] + len;
                parent[to] = v;
            }
        }
    }
}

vector<int> getPath(int s, int t, vector<int> const& parent){
    vector<int> path;
    for(int v = t; v != s; v = parent[v]) path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
