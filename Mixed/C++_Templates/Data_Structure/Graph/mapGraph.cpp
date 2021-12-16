class Graph{
private:
    unordered_map<string, list<pair<string, int>>> ls;
public:
    void addEdge(string x, string y, bool bigraph, int weight);
    void printAdjList();
};

void Graph::addEdge(string x, string y, bool bigraph, int weight) {
    ls[x].push_back(make_pair(y, weight));
    if (bigraph)
        ls[y].push_back(make_pair(x, weight));
}

void Graph::printAdjList() {
    for(const auto& self: ls){
        string vertex = self.first;
        list<pair<string,int>> neigh = self.second;
        std::cout << vertex << "-> ";
        for(const auto& edge: neigh){
            string destination = edge.first;
            int weight = edge.second;
            std::cout << "(" << destination << ", " << weight << ") ";
        }
        std::cout << "\n";
    }
}

void solve(int case_no){
    Graph g;
    g.addEdge("a", "b", true, 20);
    g.addEdge("b", "d", true, 40);
    g.addEdge("a", "c", true, 10);
    g.addEdge("d", "c", true, 40);
    g.addEdge("a", "d", false, 50);
    g.printAdjList();
}
