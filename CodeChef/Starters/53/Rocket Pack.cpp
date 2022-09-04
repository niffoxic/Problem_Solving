#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll =  pair<long long, long long>;
using plll =  pair<ll, pll>;


void solve()
{
    int m,n, k; cin >> m >>n>> k;
    vector<plll> map;
    ll x,y, c, e;
    while (k--)cin >> x >> y >> c >> e, map.push_back({x + y, {c, e} });
    map.push_back({n + m, {0, 0 } });
    sort(map.begin(), map.end());
    set<pll> left, right; right.insert({0, 0 }), left.insert({0, 0 });

    for (auto& [h, ce] : map)
    {
        auto [c, e] = ce;
        while (!right.empty())
        {
            auto [height, dis] = *right.begin();
            if (height < h)
            {
                right.erase({height, dis });
                left.erase({dis, height });
            }
            else
                break;
        }
        if (left.empty())
        {
            cout << -1 << endl;
            return;
        }
        auto [dis,height] = *left.begin();
        if (h == n + m)
        {
            cout << dis << endl;
            return;
        }
        ll nxt = dis + c;
        left.insert({nxt, h + e });
        right.insert({h + e, nxt });

    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}


