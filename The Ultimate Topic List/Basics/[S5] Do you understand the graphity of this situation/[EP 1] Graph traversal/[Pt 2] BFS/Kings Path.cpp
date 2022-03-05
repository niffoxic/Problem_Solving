#include <bits/stdc++.h>
using namespace std;

pair<int, int> kings, dest;
map<pair<int, int>, int> mp;
int canMove[2][3] = {-1, 0, 1, -1, 0, 1};
int n;

int bfs(){
    queue<pair<int, int>> q;
    q.push(kings);
    mp[kings] = 0;
    while (!q.empty()){
        pair<int, int> current = q.front(); q.pop();
        if (current == dest) return mp[current];
        for(int x: canMove[0]){
            for(int y: canMove[1]){
                int xn = current.first + x, yn = current.second + y;
                if (mp[{xn, yn}] == -1)
                    q.push({xn, yn}), mp[{xn, yn}] = mp[current] + 1;
            }
        }
    }
    return -1;
}


int main(){
    cin >> kings.first >> kings.second >> dest.first >> dest.second;
    cin >> n;
    while (n--){
        int r, a , b; cin >> r >> a >> b;
        for(int i = a; i <= b; i++) mp[{r, i}] = -1;
    }
    return cout << bfs(), 0;
}
