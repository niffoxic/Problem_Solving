#include <bits/stdc++.h>
using namespace std;


int n;
string land[51];
bool visited[2][51][51];
int movesX[]{1, -1, 0, 0};
int movesY[]{0, 0, -1, 1};
vector<pair<int, int>> possibleLand[2];

void dfs(int x, int y, int turn){
    visited[turn][x][y] = true;
    possibleLand[turn].emplace_back(x, y);
    for(int i = 0; i < 4; i++){
        int xNew = x + movesX[i];
        int yNew = y + movesY[i];
        if (xNew >= 0 && xNew < n && yNew >= 0 && yNew < n
        && !visited[turn][xNew][yNew] &&
        land[xNew][yNew] == '0') dfs(xNew, yNew, turn);
    }
}

int main(){
    cin >> n;
    int rs, cs, re, ce;
    cin >> rs >> cs >> re >> ce;
    for(int i = 0; i < n; i++) cin >> land[i];
    dfs(rs - 1, cs - 1, 0);
    dfs(re - 1, ce - 1, 1);
    int res = INT_MAX;
    for(auto i: possibleLand[0]){
        for(auto j: possibleLand[1]){
            int left = i.first - j.first, right = i.second - j.second;
            res = min(res, left * left + right * right);
        }
    }
    return cout << res, 0;
}
