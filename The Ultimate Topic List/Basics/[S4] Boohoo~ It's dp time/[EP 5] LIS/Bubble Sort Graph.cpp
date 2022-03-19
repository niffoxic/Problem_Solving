#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<int> dp;
    vector<int>::iterator iter;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        iter = upper_bound(dp.begin(), dp.end(), x);
        if (iter == dp.end()) dp.push_back(x);
        else *iter = x;
    }
    return cout << dp.size(), 0;
}
