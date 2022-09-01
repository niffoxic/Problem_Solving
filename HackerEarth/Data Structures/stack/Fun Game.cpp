#include <bits/stdc++.h

 
using namespace std;
 
using ll = long long;
using str = string;
using db = long double;
using ull = unsigned long long;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vpd = vector<pdb>;
using umi = unordered_map<int, int>;
 
#define print(x) cout << x << nn;
#define all(x) x.begin(), x.end();
 
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define nn "\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define yes cout << "yes\n"
#define no cout << "no\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
 
const int mod = 1e9+7;
 
 
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
 
    while(t--)
    {
        int n; cin >> n;
        stack<int> a;
        queue<int> b;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a.push(x);
            b.push(x);
        }
        while (!a.empty() && !b.empty()){
            if (a.top() == b.front()){
                a.pop(); b.pop();
                cout << 0 << " ";
            }else if (a.top() > b.front()){
                b.pop();
                cout << 2 << " ";
            }else{
                a.pop();
                cout << 1 << " ";
            }
        }
    }
    return 0;
}
 
