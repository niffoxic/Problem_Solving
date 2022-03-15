#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, I; cin >> n >> I;
    I *= 8;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    map<int, int> mp;
    int res = INT_MAX;
    set<int> st;
    for(int i = 0, left = 0; i < n; i++){
        mp[arr[i]]++;
        if (mp[arr[i]] == 1) st.insert(arr[i]);
        while ((int)ceil(log2(st.size())) * n > I){
            mp[arr[left]]--;
            if (!mp[arr[left]]) st.erase(arr[left]);
            left++;
        }
        res = min(res, n - i + left - 1);
    }
    return cout << res, 0;
}
