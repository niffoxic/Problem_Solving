#include <bits/stdc++.h>
using namespace std;

using str = string;
using umii = unordered_map<int, int>;



int main()
{
    int n; cin >> n;
    str s1; cin >> s1;
    umii res;
    int ans = 0, val = 0, curr = 0;
    int counts = 0;
    for(int i = 0; i < n; i++){
        if (s1[i] == '0') counts++;
        else counts--;
        if (counts > 0){
            ans = i + 1;
        }else{
            if(res.find(counts - 1) != res.end()){
                ans = max(ans, i - res[counts - 1]);
            }
        }
        if (res.find(counts) == res.end())
            res[counts] = i;
    }
    cout << ans << "\n";
    return 0;
}
