#include <bits/stdc++.h>

using namespace std;

#define template_size 100009
using ll = long long;
ll arr[template_size], n, s;
ll temp[template_size];


ll purchase(int k){
    for(int i = 0; i < n; i++) temp[i] = arr[i] + (i + 1LL) * k;
    sort(temp, temp + n);
    ll res = 0;
    for(int i = 0; i < k; i++) res += temp[i];
    return res;
}


int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int left = 0, right = n + 1;
    while (left < right - 1){
        int mid = left + ((right - left) >> 1);
        if (purchase(mid) <= s) left = mid;
        else right = mid;
    }
    return cout << left << " " << purchase(left), 0;
}
