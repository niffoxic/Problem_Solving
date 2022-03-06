#include <bits/stdc++.h>
using namespace std;

#define template_size 200001

int n, color[template_size], whichOne[template_size], x, y, z;
vector<int> graph[template_size];


void dfs(int v, int defaultColor = 0){
    whichOne[v] = defaultColor? whichOne[defaultColor] + (color[v] ^ color[defaultColor]): 1;
    if (whichOne[v] > whichOne[z]) z = v;
    for(int u: graph[v])
        if (u != defaultColor) dfs(u, v);
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> color[i];
    for(int i = 1; i < n; i++) cin >> x >> y, graph[x].push_back(y),
    graph[y].push_back(x);
    dfs(1), dfs(z);
    cout << (whichOne[z] >> 1);
    return 0;
}
