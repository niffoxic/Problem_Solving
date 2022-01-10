#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, t; cin >> n; t = n;
    vector<vector<int>> res;
    while(t--){
        int a, b; cin >> a >> b;
        res.push_back({b, a});
    }sort(res.begin(), res.end());
    bool yea = false;
    for(int i = 0; i < n - 1; i++)
        if (res[i][1] > res[i + 1][1] && res[i][0] != res[i + 1][0])
            yea = true;
    cout << (yea?"Happy Alex": "Poor Alex");
    return 0;
}
