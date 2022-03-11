#include <bits/stdc++.h>

using namespace std;
#define COL 501

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};

bool valid(int x, int y, int n, int m, int M[][COL]){
    return x >= 0 &&  y >= 0 && x < n && y < m && M[x][y] == 1;
}

void dfs(int x, int y, int M[][COL], int n, int m){
    M[x][y] = 0;
    for(int i = 0; i < 8; i++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if (valid(nx, ny, n, m, M)) dfs(nx, ny, M, n, m);
    }
}

int countIslands(int M[][COL], int n, int m) {
    int res = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if (valid(i, j, n, m, M)) dfs(i, j, M, n, m), res++;
    return res;
}
