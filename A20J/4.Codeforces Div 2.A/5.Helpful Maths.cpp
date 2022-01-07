#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s; cin >> s;
    int st[3] {0};
    for(char i : s)
        if ((int)i > 48)
            st[i - '1']++;
 
    string res;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < st[i]; j++){
            res += char(i + 49);
            res += '+';
        }
    }
    cout << res.substr(0, res.size() - 1);
}
