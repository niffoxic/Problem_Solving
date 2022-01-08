#include<bits/stdc++.h>
using namespace std;


int main()
{
    int s, n; cin >> s >> n;
    vector<vector<int>> d;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        d.push_back({x, y});
    }
    sort(d.begin(), d.end());
    bool yea = true;
    for(auto i: d){
        if (i[0] >= s){
            yea = false;
            break;
        }
        s += i[1];
    }
    cout << ((yea?"YES": "NO"));
    return 0;
}
