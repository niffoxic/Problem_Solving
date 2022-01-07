#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s1, s2;cin >> s1 >> s2;
    int res = 0;
    for(int i = 0; i < s1.size(); i++){
        int a = ((int)s1[i] < 97)? (s1[i] - 'A') + 'a': (int)s1[i];
        int b = ((int)s2[i] < 97)? (s2[i] - 'A') + 'a': (int)s2[i];
        if (a > b){
            res = 1; break;
        }
        if (b > a){
            res = -1; break;
        }
    }
    cout << res;
}
