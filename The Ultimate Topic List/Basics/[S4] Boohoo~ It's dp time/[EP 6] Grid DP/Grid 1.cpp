#include <bits/stdc++.h>
using namespace std;


#define template_size 1001
string grid[template_size];
int dp[template_size][template_size];
const int mod = 1e9 + 7;
int n, m;


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> grid[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (grid[i - 1][j - 1] == '.'){
                if (i == 1 && j == 1) dp[i][j] = 1;
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    return cout << dp[n][m], 0;
}
