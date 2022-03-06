struct edge {
    int vertex, u, w;
};
vector<edge> graph;

class BellmanFordNevPath {
private:
    vector<int> dis;
    vector<int> parent;
    int endPoint, _n, _m, _s;
public:
    void build(int n, int m, int source) {
        _n = n, _m = m, _s = source;
        dis.resize(n, INT_MAX);
        parent.resize(n, -1);
        dis[source] = 0;
        for (int i = 0; i < n; i++) {
            endPoint = -1;
            for (int j = 0; j < m; j++) {
                if (dis[graph[j].u] > dis[graph[j].vertex] + graph[j].w) {
                    dis[graph[j].u] = dis[graph[j].vertex] + graph[j].w;
                    parent[graph[j].u] = graph[j].vertex;
                    endPoint = graph[j].u;
                }
            }
        }
    }
    vector<int> askPath(int destiny) {
        vector<int> path;
        if (endPoint == -1) return {-1};
        int root = endPoint;
        for (int i = 0; i < _n; i++)
            root = parent[root];

        for (int cur = root;; cur = parent[cur]) {
            path.push_back(cur);
            if (cur == root && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
