
struct edge{
    int u, v, w;
};
vector<edge> graph;

template <class T>
void bellmanFort(T _n, T _u, T _m){
    vector<int> dis(_n, INT_MAX);
    dis[_u] = 0;
    for(;;){
        bool any = false;
        for(int j = 0; j < _m; j++){
            if (dis[graph[j].v] > dis[graph[j].u] + graph[j].w){
                any = true;
                dis[graph[j].v] = dis[graph[j].u] + graph[j].w;
            }
        }
        if (!any) break;
    }
}
