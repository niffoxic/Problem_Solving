#include<bits/stdc++.h>
using namespace std;

#define lim (1e6 + 1)
using lld = long double;

#define rep(i,start,lim) for(lld i=start;i < lim;i++)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n,ans = 0,w,h;
    cin >> n;
    rep(i,1,n+1) {
        cin>>w>>h;
        if(10*w >= 16*h and 10*w <= 17*h) ans++;
        else if(10*h >= 16*w and 10*h <= 17*w) ans++;
        else continue;
    }
    cout<<ans;
    return 0;
}
