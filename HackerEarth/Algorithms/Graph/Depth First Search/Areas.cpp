#include <bits/stdc++.h>
using namespace std;

#define template_size 1000005

string graph[template_size];
int n, m, res;

int dx[]{1, -1, 0, 0};
int dy[]{0, 0, -1, 1};

bool notValid(int x, int y){
    return x < 0 || y < 0 || x == n || y == m || graph[x][y] == '#';
}

void dfs(int x, int y){
    graph[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (!notValid(nx, ny)) res++, dfs(nx, ny);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> graph[i];
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (graph[i][j] == '.'){
                res = 1; dfs(i, j);
                ans.push_back(res);
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto i: ans) cout << i << " ";
    cout << "\n";
}


int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
