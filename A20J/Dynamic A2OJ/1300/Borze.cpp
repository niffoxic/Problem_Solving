#include <bits/stdc++.h>
using namespace std;

string s, t;
int n;

int main(){
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++){
        if (s[i] == '.') t += '0';
        else if (n > i + 1 && s[i] == '-' && s[i + 1] == '.') t += '1', i++;
        else if (n > i + 1 && s[i] == '-' && s[i + 1] == '-') t += '2', i++;
    }
    cout << t;
    return 0;
}
