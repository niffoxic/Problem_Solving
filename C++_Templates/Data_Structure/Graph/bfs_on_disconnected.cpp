void bfs(vector<int>adj[], int self, bool visited[]){
    queue<int> q;
    visited[self] = true;
    q.push(self);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ";
        for(auto i: adj[current]){
            if (!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


void bfsDisconnected(vector<int>adj[], int v){
    bool visited[v + 1];
    for(int i = 0; i < v; i++) visited[i] = false;
    for(int i = 0; i < v; i++)
        if (!visited[i])
            bfs(adj, i, visited);
}

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve(int case_no){
    int V=7;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,4,6);
    bfsDisconnected(adj,V);
}
