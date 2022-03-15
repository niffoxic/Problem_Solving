#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k, a = 0, b = 0, res = 0;
    cin >> n >> k;
    string s; cin >> s;
    int right = 0;
    for(char i : s){
        i - 'a'? b++: a++;
        if (min(a, b) > k) s[right++] - 'a'? b--: a--;
        res = max(res, a + b);
    }
    cout << res;
    return 0;
}
