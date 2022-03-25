#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, t; cin >> n >> t;
    string s; cin >> s;
    for(int i = 0; i < t; i++){
        for(int j = 1; j < n; j++){
            if (s[j - 1] == 'B' && s[j] == 'G') swap(s[j - 1], s[j]), j++;
        }
    }
    cout << s;
    return 0;
}
