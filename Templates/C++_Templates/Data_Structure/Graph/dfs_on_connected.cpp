void dfs(vector<int>adj[], vector<bool>& visited, int current){
    cout << current << " ";
    visited[current] = true;
    for(int i: adj[current]){
        if (!visited[i]){
            dfs(adj, visited, i);
        }
    }
}


void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve(int case_no){
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,3,4);
    vector<bool> vertex(V + 1);
    for(int i: vertex) i = false;
    dfs(adj, vertex, 0);
}
