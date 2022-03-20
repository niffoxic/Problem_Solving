#include <bits/stdc++.h>
using namespace std;

#define template_size 52
int arr[template_size], dp[template_size], suffix[template_size];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = n - 1; i >= 0; i--){
        suffix[i] = suffix[i + 1] + arr[i];
        dp[i] = max(dp[i + 1], suffix[i + 1] - dp[i + 1] + arr[i]);
    }
    cout << suffix[0] - dp[0] << " " << dp[0] << "\n";
    return 0;
}
