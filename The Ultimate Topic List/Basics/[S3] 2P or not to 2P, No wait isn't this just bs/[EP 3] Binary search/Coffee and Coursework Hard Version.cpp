#include <bits/stdc++.h>

using namespace std;

#define template_size 200009
using ll = long long;

ll arr[template_size];
ll n, pages;

ll valid(int x){
    ll sum = 0;
    for(int i = 0; i < n; i++) sum += max(0LL, arr[i] - i / x);
    return sum;
}


int main()
{
    cin >> n >> pages;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<>());
    int left = 1, right = n + 1;
    int res = -1;
    while (left <= right){
        int mid = left + ((right - left) >> 1);
        if (valid(mid) >= pages) right = mid - 1, res = mid;
        else left = mid + 1;
    }
    return cout << (res > n? -1: res), 0;
}
