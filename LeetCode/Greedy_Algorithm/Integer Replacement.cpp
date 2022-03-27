class Solution1 {
public:
    using ll = unsigned long long;
    ll recursion(ll n){
        if (n == 1) return 0;
        if (n < 1) return 1 + recursion(n + 1);
        if (!(n & 1)) return 1 + recursion(n >> 1);
        int left, right;
        left = 1 + recursion(n + 1);
        right = 1 + recursion(n - 1);
        return min(left, right);
    }

    ll integerReplacement(ll n) {
        return recursion(n);
    }
};

class Solution2 {
public:
    using ll = unsigned long long;
    unordered_map<ll, ll> mp;
    ll recursion(ll n){
        if (mp.find(n) != mp.end()) return mp[n];
        if (n == 1) return 0;
        if (n < 1) return 1 + recursion(n + 1);
        if (!(n & 1)) return 1 + recursion(n >> 1);
        int left, right;
        left = 1 + recursion(n + 1);
        right = 1 + recursion(n - 1);
        mp[n] = min(left, right);
        return mp[n];
    }

    ll integerReplacement(ll n) {
        return recursion(n);
    }
};


class Solution3 {
public:
    using ll = unsigned long long;

    ll integerReplacement(ll n) {
        int res = 0;
        while (n != 1){
            if (n == 3) return res + 2;
            if (!(n & 1)) n >>= 1;
            else if (!(((n - 1) >> 1) & 1)) n--;
            else n++;
            res++;
        }
        return res;
    }
};
