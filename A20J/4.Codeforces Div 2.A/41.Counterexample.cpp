#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(){
     ll l, r; cin >> l >> r;
     if (l % 2 != 0) l++;
     if (abs(l - r) < 2) cout << -1;
     else cout << l << " " << l + 1 << " " << l + 2;
     return 0;
}
