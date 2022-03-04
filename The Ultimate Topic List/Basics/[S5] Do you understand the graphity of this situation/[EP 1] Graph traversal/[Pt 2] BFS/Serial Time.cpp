#include <bits/stdc++.h>
using namespace std;


char tap[11][11][11];
queue<tuple<int, int, int>> q;
int n, m, k;
int res = 0;
int dx[]{1, -1, 0, 0, 0, 0};
int dy[]{0, 0, -1, 1, 0, 0};
int dz[]{0, 0, 0, 0, -1, 1};

void bfs(int x, int y, int z){
    if (x < 0 || y < 0 || z < 0 || x == k || y == n || z == m) return;
    if (tap[x][y][z] == '#') return;
    tap[x][y][z] = '#';
    res++;
    for(int i = 0; i < 6; i++) q.emplace(x + dx[i], y + dy[i], z + dz[i]);
}

int main(){
    cin >> k >> n >> m;
    for(int i = 0 ; i < k; i++)
        for(int j = 0; j < n; j++)
            for(int l = 0; l < m; l++) cin >> tap[i][j][l];
    int x, y; cin >> x >> y;
    x--, y--;
    q.emplace(0, x, y);
    while (!q.empty()){
        tuple<int, int, int> current = q.front();
        q.pop();
        bfs(get<0>(current), get<1>(current), get<2>(current));
    }
    cout << res << "\n";
    return 0;
}
