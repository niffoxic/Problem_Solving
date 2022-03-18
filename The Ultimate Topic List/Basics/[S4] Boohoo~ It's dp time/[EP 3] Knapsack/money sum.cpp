#include <bits/stdc++.h>
using namespace std;

int n, coins[1001];
const int mV = 1e5 + 1;
int dp[mV];


void dpSolve(){
    int val = 0; for(int i = 0; i < n; i++) val += coins[i];
    dp[0] = 1;
    for(int i = 0; i < n; i++) for(int j = val; j >= coins[i]; j--) dp[j] = dp[j] + dp[j - coins[i]];
    int counts = 0; for(int i = 1; i <= val; i++) if (dp[i]) counts++;
    cout << counts << "\n";
    for(int i = 1; i <= val; i++) if (dp[i]) cout << i << " ";
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> coins[i];
    dpSolve();
    return 0;
}
