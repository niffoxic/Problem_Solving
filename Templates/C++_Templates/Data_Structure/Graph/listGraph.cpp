class listGraph{
private:
    int vertex;
    list<int> *ls;
public:
    explicit listGraph(int vertex);
    void addEdge(int x, int y);
    void printAdjList();
};

listGraph::listGraph(int vertex) {
    this->vertex = vertex;
    ls = new list<int>[vertex];
}

void listGraph::addEdge(int x, int y) {
    ls[x].push_back(y);
    ls[y].push_back(x);
}

void listGraph::printAdjList() {
    for(int i = 0; i < vertex; i++){
        for(int neigh: ls[i]){
            std::cout << neigh << " ";
        }
        std::cout << "\n";
    }
}
