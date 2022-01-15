#include <bits/stdc++.h>
using namespace std;

int remove_z(int n){
    string s = to_string(n);
    string res;
    for(auto i: s)
        if (i != '0') res += i;
    return stoi(res);
}

int main(){
    int a, b; cin >> a >> b;
    int left = a + b;
    int right = remove_z(a) + remove_z(b);
    if (remove_z(left) == right)
        cout << "YES";
    else cout << "NO";
    return 0;
}
