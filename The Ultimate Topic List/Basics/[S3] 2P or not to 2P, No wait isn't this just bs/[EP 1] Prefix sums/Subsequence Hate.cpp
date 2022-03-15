#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int sum0 = 0, sum1 = 0;
        for(auto i: s) sum0 += i == '0', sum1 += i == '1';
        int pre1 = 0, pre0 = 0;
        int res = min(sum0, sum1);
        for(auto i: s){
            pre1 += i == '1', sum1 -= i == '1';
            pre0 += i == '0', sum0 -= i == '0';
            res = min(res, pre1 + sum0);
            res = min(res, pre0 + sum1);
        }
        cout << res << "\n";
    }
    return 0;
}
