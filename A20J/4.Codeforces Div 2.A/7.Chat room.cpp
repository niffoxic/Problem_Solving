#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s; cin >> s;
    string hello = "hello";
    int i = 0, j = 0;
    while (j < s.size() && i < 5){
        if (hello[i] == s[j])
            i++;
        j++;
    }
    cout << ((i == 5)? "YES": "NO");
}
