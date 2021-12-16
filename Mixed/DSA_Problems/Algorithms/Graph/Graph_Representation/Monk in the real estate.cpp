
class Graph{
    unordered_set<int> cities;
public:
    void addRoad(int v, int u);
    int getCity();
};

void Graph::addRoad(int v, int u) {
    cities.insert(v);
    cities.insert(u);
}

int Graph::getCity() {
    return (int)cities.size();
}

void solve(int case_no){
    int r; cin >> r;
    Graph g;
    while(r--){
        int a, b; cin >> a >> b;
        g.addRoad(a, b);
    }
    cout << g.getCity() << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
