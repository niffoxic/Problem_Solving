#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n; cin >> n;
    ll arr[n];
    ll evenSuf = 0, oddSuf = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i & 1) oddSuf += arr[i];
        else evenSuf += arr[i];
    }
    int res = 0;
    ll preOdd = 0, preEven = 0;
    for(int i = 0; i < n; i++){
        if (i & 1) oddSuf -= arr[i];
        else evenSuf -= arr[i];

        if (evenSuf + preOdd == oddSuf + preEven) res++;
        if (i & 1) preOdd += arr[i];
        else preEven += arr[i];
    }
    cout << res << "\n";
    return 0;
}
