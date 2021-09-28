void bfs(vector<int>adj[], int v, int self){
    bool visited[v + 1];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    visited[self] = true;
    q.push(self);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto other: adj[u]){
            if (visited[other] == false){
                visited[other] = true;
                q.push(other);
            }
        }
    }
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve(int case_no){
    int vertex = 5;
    vector<int> adj[vertex];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    bfs(adj, vertex, 0);
}
