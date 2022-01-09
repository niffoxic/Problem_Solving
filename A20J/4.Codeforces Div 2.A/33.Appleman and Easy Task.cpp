#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    string s; for(int i = 0; i < n; i++){
        string t; cin >> t; s+= t;
    }
    string res = s;
    reverse(s.begin(), s.end());
    cout << ((res == s)? "YES": "NO");
    return 0;
}
