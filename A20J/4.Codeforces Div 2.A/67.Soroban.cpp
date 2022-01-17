#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<string> s;
    if (!n)
        s.emplace_back("O-|-OOOO");
    while (n){
        int current = n % 10;
        string left = "--";
        left[current >= 5] = 'O';
        if (current >= 5) current -= 5;
        string right;
        int lo = 4 - current;
        while (current--)
            right += 'O';
        right += '-';
        while (lo--) right+= 'O';
        n /= 10;
        s.push_back(left + '|' + right);
    }
    for(auto &i: s)
        cout << i << "\n";
    return 0;
}
