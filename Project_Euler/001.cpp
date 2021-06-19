#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

using ll = long long;
using str = string;
using db = long double;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pdb = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pdb>;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define up upper_bound

const int mod = 1e9+7;

ull add_up(ull n, ull d){
    n /= d;
    return d * n * (n + 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while(t--) {
        ull n;
        cin >> n;
        int a = 3, b = 5;
        cout << add_up(n - 1, a) + add_up(n - 1, b) - add_up(n - 1, a * b) << "\n";
    }

    return 0;
}
