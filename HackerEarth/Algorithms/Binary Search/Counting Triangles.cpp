#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;


int main()
{
    int n; cin >> n;
    map<str, ll> res;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ll arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        str s1 = to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]);
        if (res.find(s1) != res.end() && res[s1] == 1){
            res[s1] = 0;
            ans--;
        }
        if (res.find(s1) == res.end()){
            ans++; res[s1]++;
        }
    }
    return cout << ans,  0;
}
