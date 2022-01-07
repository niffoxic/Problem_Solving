#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s; cin >> s;
    unordered_set<char>st{'a', 'o', 'y', 'e', 'u', 'i'};
    string res;
    for(auto i: s){
        char ch = ((int)i < 97)? (char)((i - 'A') + 'a'): i;
        if (st.find(ch) == st.end()){
            res += '.';
            res += ch;
        }
    }
    cout << res;
}
