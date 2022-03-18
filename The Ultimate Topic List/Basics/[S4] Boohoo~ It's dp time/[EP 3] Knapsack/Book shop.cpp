#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxX = 1e5;

ll n, x;
int price[1001], pages[maxX + 1];
int dp[1001][maxX + 1];


int recursion(int index, int money){
    if (!index || !money) return 0;
    int left = 0, right = 0;
    if (price[index - 1] <= money) left = recursion(index - 1, money - price[index - 1]) + pages[index - 1];
    right = recursion(index - 1, money);
    return max(left, right);
}


int dpImplementation(){
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= x; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
        }
    }
    return dp[n][x];
}


int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    return cout << dpImplementation(), 0;
}
