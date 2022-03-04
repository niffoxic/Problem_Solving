#include <bits/stdc++.h>
using namespace std;

int n, m, k, sx, sy;
char maze[1001][1001];
int dis[1001][1001];
string traverse = "DLRU";
int dx[]{1, 0, 0, -1};
int dy[]{0, -1, 1, 0};


bool check(int x, int y){
    return x < 0 || y < 0 || x == n || y == m || maze[x][y] == '*';
}

void bfs()
{
    dis[sx][sy] = 1;
    queue<pair<int, int>> q; q.emplace(sx, sy);
    while (!q.empty()){
        pair<int, int> current = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = current.first + dx[i], ny = current.second + dy[i];
            if (!check(nx, ny) && !dis[nx][ny]){
                q.emplace(nx, ny);
                dis[nx][ny] = dis[current.first][current.second] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k; k++;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            if (maze[i][j] == 'X') sx = i, sy = j;
        }
    }
    bfs();
    string res;
    while (--k){
        for(int i = 0; i < 4; i++){
            int nx = sx + dx[i], ny = sy + dy[i];
            if (!check(nx, ny) && dis[nx][ny] <= k){
                sx = nx, sy = ny;
                res += traverse[i];
                goto done;
            }
        }
        return cout << "IMPOSSIBLE", 0;
        done:;
    }
    return cout << res, 0;
}
