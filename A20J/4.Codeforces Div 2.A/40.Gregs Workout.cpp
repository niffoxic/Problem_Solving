#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int res[3] = {0}, idx = 0;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        res[i % 3]+= t;
        if (res[idx] < res[i % 3]) idx = i % 3;
    }vector<string>ans{"chest", "biceps", "back"};
    cout << ans[idx];
    return 0;
}
