#include <bits/stdc++.h>
using namespace std;

#define template_size 100001
int n;
vector<int> graph[template_size];
int res[template_size];


int main(){
    cin >> n;
    for(int  i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(i);
        graph[v].push_back(i);
        res[i] = -1;
    }
    pair<int, int> mNode (0, 0);
    for(int i = 1; i <= n; i++)
        mNode = max(mNode, make_pair((int)graph[i].size(), i));
    int allocate = 0;
    for(auto i: graph[mNode.second]) res[i] = allocate++;
    for(int i = 1; i < n; i++){
        if (res[i] == -1)
            res[i] = allocate++;
        cout << res[i] << "\n";
    }
    return 0;
}
