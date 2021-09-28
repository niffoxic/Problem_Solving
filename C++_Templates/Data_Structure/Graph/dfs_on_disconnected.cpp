
void proc(vector<int>adj[], bool visited[], int self){
    visited[self] = true;
    cout << self << " ";
    for(auto i: adj[self]){
        if (!visited[i])
            proc(adj, visited, i);
    }
}


void dfs(vector<int>adj[], int vertex){
    bool visited[vertex];
    for(int i = 0; i < vertex; i++) visited[i] = false;
    for(int i = 0; i < vertex; i++){
        if (!visited[i]){
            proc(adj, visited, i);
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
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    dfs(adj, V);
}
