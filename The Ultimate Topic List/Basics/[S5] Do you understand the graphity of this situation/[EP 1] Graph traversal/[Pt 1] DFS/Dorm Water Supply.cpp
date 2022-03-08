#include <bits/stdc++.h>
using namespace std;

#define template_size 1050

using pii = pair<int, int>;

int outDeg[template_size], diameter[template_size];
bool inDeg[template_size];

pii dfs(int pos){
    if (!outDeg[pos]) return {pos, 1 << 30};
    pii res = dfs(outDeg[pos]);
    return {res.first, min(res.second, diameter[pos])};
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0, a, b, d; i < m; i++){
        cin >> a >> b >> d;
        inDeg[b] = true;
        outDeg[a] = b, diameter[a] = d;
    }
    vector<int> root;
    for(int i = 1; i <= n; i++) if (!inDeg[i] && outDeg[i]) root.push_back(i);
    cout << root.size() << "\n";
    for(auto i: root){
        pii res = dfs(i);
        cout << i << " " << res.first << " " << res.second << "\n";
    }
}
