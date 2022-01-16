#include <bits/stdc++.h>
using namespace std;


int main(){
    int k; cin >> k;
    int arr[10] = {0};
    for(int i = 0; i < 4; i++){
        string s; cin >> s;
        for(auto j: s)
            if (j != '.')
                arr[j - '0']++;
    }
    bool yea = true;
    for(int i : arr)
        yea &= (k * 2 >= i);
    return cout << (yea?"YES": "NO"), 0;
}
