#include <bits/stdc++.h>

using namespace std;


long long countPairs(vector<int> &nums, int k) {
    using ll = long long;
    ll res = 0;
    unordered_map<int, int> mp;
    for (auto i: nums) {
        ll gcd = __gcd(k, i);
        ll x = k / gcd;
        for (auto it:mp) if (it.first % x == 0) res += it.second;
        mp[gcd]++;
    }
    return res;
}
