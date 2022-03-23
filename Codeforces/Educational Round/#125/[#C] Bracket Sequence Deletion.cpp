#include <bits/stdc++.h>
using namespace std;


int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        int res = 0, left = 0;
        while(left + 1 < n){
            if (s[left] == '(' || s[left] == ')' && s[left + 1] == ')') left += 2;
            else{
                int right = left + 1;
                while (right < n && s[right] != ')') right++;
                if (right == n) break;
                left = right + 1;
            }
            res++;
        }
        cout << res << " " << n - left << "\n";
    }
    return 0;
}
