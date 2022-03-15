#include <bits/stdc++.h>
using namespace std;


#define template_size 100009
using ll = long long;
ll arr[template_size], mark[template_size], brr[template_size];
int q[template_size][3];


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> brr[i];
    for(int i = 1; i <= m; i++) cin >> q[i][0] >> q[i][1] >> q[i][2];
    while (k--){
        int left, right;
        cin >> left >> right;
        mark[left]++;
        mark[right + 1]--;
    }
    for(int i = 1; i <= m; i++){
        mark[i] += mark[i - 1];
        arr[q[i][0]] += mark[i] * q[i][2];
        arr[q[i][1] + 1] -= mark[i] * q[i][2];
    }
    for(int i = 1; i <= n; i++) arr[i] += arr[i - 1],
    cout << arr[i] + brr[i] << " ";
}
