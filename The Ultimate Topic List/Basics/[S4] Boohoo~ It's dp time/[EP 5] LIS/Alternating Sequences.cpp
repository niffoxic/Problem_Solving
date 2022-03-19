#include <bits/stdc++.h>
using namespace std;

#define template_size 5001
int n, dp[template_size], arr[template_size], sign[template_size];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], sign[i] = arr[i] > 0;
    for(int i = 0; i <= n; i++) dp[i] = 1;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if (abs(arr[i]) > abs(arr[j]) && (sign[i] ^ sign[j]))
                dp[i] = max(dp[i], dp[j] + 1);
    return cout << *max_element(dp, dp + n), 0;
}
