#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> res(n, '@');
    int mid = n >> 1;
    int left = mid - 1, right = mid;
    if (n & 1) res[mid] = s[0], right++;
    int turn = 0;
    for(int i = (n & 1)? 1: 0; i < n; i++){
        if (!turn) res[left] = s[i], left--, turn = 1;
        else turn = 0, res[right] = s
                [i], right++;
    }
    for(auto i: res){
        if (i == '@') break;
        cout << i;
    }
    return 0;
}
