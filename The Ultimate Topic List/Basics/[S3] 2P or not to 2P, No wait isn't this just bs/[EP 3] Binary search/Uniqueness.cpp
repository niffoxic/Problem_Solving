#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    map<int, int> mp;
    int res = n - 1;
    for(int i = 0; i < n; i++){
        bool there = true;
        for(int j = 0; j < i && there; j++){
            mp[arr[j]]++;
            if (mp[arr[j]] == 2) there = false;
        }
        int current = n;
        for(int j = n - 1; j >= i && there; j--){
            mp[arr[j]]++;
            if (mp[arr[j]] == 1) current = j;
            else break;
        }
        if (there) res = min(res, current - i);
        mp.clear();
    }
    return cout << res, 0;
}
