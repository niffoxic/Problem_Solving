#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int x[] = {0, 0, 0, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int y[] = {1, 2, 3, 1, 2, 3, 0, 0, 0, -1, -2, -3};

bool isvalid(int r, int c) {
    return (r < 20 && r >= 0 && c >= 0 && c < 20);
}

int main() {
    int grid[20][20];
    for (auto & i : grid) for (int & j : i) cin >> j;

    ull res = 0, current = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int s = 0; s < 12; ++s) {
                if (s % 3 == 0) res = max(res, current), current = grid[i][j];
                if (isvalid(i + x[s], j + y[s])) current *= grid[i + x[s]][j + y[s]];
            }
            res = max(res, current);
        }
    }
    cout << res;
    return 0;
}
