#include <bits/stdc++.h>
using namespace std;
#define template_size 2020
using ll = long long;


int item[template_size], val[template_size], n, s;
ll dp[template_size][template_size];


ll solve(int w, int index){
    if (!index || !w) return 0;
    if (dp[index][w] != -1) return dp[index][w];
    ll left = 0, right;
    if (item[index - 1] <= w) left = solve(w - item[index - 1], index - 1) + val[index - 1];
    right = solve(w, index - 1);
    return dp[index][w] = max(left, right);
}


int main(){
    cin >> s >> n;
    for(int i = 0; i < n; i++) cin >> item[i] >> val[i];
    for(int i = 0; i <= n; i++) for(int j = 0; j <= s; j++) dp[i][j] = -1;
    cout << solve(s, n);
    return 0;
}
