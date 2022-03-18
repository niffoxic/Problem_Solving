#include <bits/stdc++.h>
using namespace std;
#define template_size 100009
using ll = long long;
int item[template_size], val[template_size], n, s;
ll dp[110][100009];


ll recursion(int w, int index){
    if (!index || !w) return 0;
    ll left = 0, right;
    if (item[index - 1] <= w) left = recursion(w - item[index - 1], index - 1) + val[index - 1];
    right = recursion(w, index - 1);
    return max(left, right);
}

ll dpSolve(){
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= s; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= s; w++){
            if (w >= item[i - 1]) dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - item[i - 1]]);
            else dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][s];
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> item[i] >> val[i];
    for(int i = 0; i <= n; i++) for(int j = 0; j <= s; j++) dp[i][j] = -1;
    cout << dpSolve();
    return 0;
}
