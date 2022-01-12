#include<bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ll n; cin >> n;
    int arr[n];
    unordered_set<int>st;
    for(int i = 0; i < n; i++){
        cin >> arr[i]; st.insert(arr[i]);
    }
    ll left = 0, right = 0, dist = 0, res = 0;
    unordered_map<ll, ll> mp;

    while (right < n){
        if (!mp[arr[right]])
            dist++;
        mp[arr[right]]++;

        if (st.size() == dist){
            while (left <= right){
                mp[arr[left]]--;
                res += (n - right);
                if (!mp[arr[left]]){
                    dist--, left++;
                    break;
                }
                left++;
            }
        }
        right++;
    }
    return cout << res, 0;
}
