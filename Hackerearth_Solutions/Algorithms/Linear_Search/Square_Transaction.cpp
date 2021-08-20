#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

using ll = long long;


using vll = vector<ll>;


#define print(x) cout << (x) << nn;


const int mod = 1e9+7;
const int dp_size = 1e5;

void solve(int case_no)
{
    int n; cin >> n;
    vll arr(n + 1);
    arr[0] = 0;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll q;
    cin >> q;
    while(q--){
        int check;
        cin >> check;
        auto it = lower_bound(arr.begin(), arr.end(), check) - arr.begin();
        if(it > n)
            print(-1)
        else
            print(it)
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    //cin >> test_case;
    for(int i = 1; i <= test_case; i++) solve(i);

    return 0;
}
