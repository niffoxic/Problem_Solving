#include <bits/stdc++.h>
using namespace std;

#define template_size 200009
using ll = long long;
ll arr[template_size];


int main(){
    ll n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    ll left = 0, right = n + 1, marked = 0;
    ll sum1 = 0, sum2 = 0;
    while (left < right){
        if (sum1 < sum2) sum1 += arr[++left];
        else if (sum2 < sum1) sum2 += arr[--right];
        else{
            marked = left;
            sum1 += arr[++left];
            sum2 += arr[--right];
        }
    }
    return cout << accumulate(arr + 1, arr + marked + 1, 0ll), 0;
}



