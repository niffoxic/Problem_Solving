#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m; cin >> n >> m;
    bool pos = false;
    for(int i = 0; i < n && !pos; i++)
    {
        for(int j = 0; j < m && !pos; j++){
            int t; cin >> t;
            if ((i == 0 || i == n - 1
            || j == 0 || j == m - 1) && t) pos = true;
        }
    }
    return cout << (pos?2: 4) ,0;
}
