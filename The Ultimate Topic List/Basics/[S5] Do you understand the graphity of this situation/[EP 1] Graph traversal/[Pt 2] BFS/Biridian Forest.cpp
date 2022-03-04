#include <bits/stdc++.h>
using namespace std;

int forest[1001][1001], timeTaken[1001][1001];
queue<int> xCords, yCords;
int r, c;
int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};

void bfs(int x, int y, int timePassed){
    if (x < 0 || y < 0 || x == r || y == c || forest[x][y] == -1 || timeTaken[x][y]) return;
    timeTaken[x][y] = timePassed;
    for(int i = 0; i < 4; i++)
        xCords.push(x + dx[i]), yCords.push(y + dy[i]);
}

int main(){
    cin >> r >> c;
    int startX, startY;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char current; cin >> current;
            if (current == 'T') forest[i][j] = -1;
            else if (current == 'S') startX = i, startY = j;
            else if (current == 'E') xCords.push(i), yCords.push(j);
            else forest[i][j] = current - '0';
        }
    }
    int runningTime = 1;
    while (!xCords.empty()){
        int n = xCords.size();
        for(int i = 0; i < n; i++){
            bfs(xCords.front(), yCords.front(), runningTime);
            xCords.pop();
            yCords.pop();
        }
        runningTime++;
    }
    int res = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if (timeTaken[i][j] <= timeTaken[startX][startY] && timeTaken[i][j] && forest[i][j] != -1) res += forest[i][j];
    return cout << res << "\n", 0;
}
