#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k, left = 0, res = 0;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if (sum > k) sum -= arr[left], left++;
        else res++;
    }
    cout << res << "\n";
}
