#include <bits/stdc++.h>
using namespace std;

#define template_size 200005
int dp[template_size];

int main(){
    int n; cin >> n;
    for(int i = 0, t; i < n; i++) cin >> t, dp[t] += t;
    for(int i = 2; i < template_size; i++)
        dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
    return cout << *max_element(dp, dp + n), 0;
}
