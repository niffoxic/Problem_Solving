#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        string s1, s2; cin >> s1 >> s2;
        int res = 1;
        if (s1.size() != s2.size()) res = 0;
        for(int i = 0; i < s1.size() && res; i++)
            if (s1[i] != s2[i] && (s1[i] != '?' && s2[i] != '?')) res = 0;
        cout << (res?"Yes": "No") << "\n";
    }
}
