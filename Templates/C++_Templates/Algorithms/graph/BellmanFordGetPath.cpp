
struct edge{
    int u, v, w;
};
vector<edge> graph;

class BellmanFordPath{
private:
    vector<int> dis;
    vector<int> parent;
public:
    void build(int n, int m, int source){
        dis.resize(n, INT_MAX);
        parent.resize(n, -1);
        dis[source] = 0;
        for(;;){
            bool any = false;
            for(int i = 0; i < m; i++){
                if (dis[graph[i].v]> dis[graph[i].u] + graph[i].w){
                    any = true;
                    dis[graph[i].v] = dis[graph[i].u] + graph[i].w;
                    parent[graph[i].v] = graph[i].u;
                }
            }
            if (!any) break;
        }
    }
    vector<int> askPath(int destiny){
        vector<int> path;
        if (dis[destiny] == INT_MAX) return {-1};
        for(int i = destiny; i != -1; i = parent[destiny])
            path.push_back(i);
        reverse(path.begin(), path.end());
        return path;
    }
};
