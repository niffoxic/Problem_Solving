#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, ig = "WUB", res, hold; cin >> s;
    int i = 0, j = 0;
    while(i < s.size()){
        if (j == 3){
            j = 0;
            hold = "";
            if (!res.empty() && res[res.size() - 1] != ' ')
                res += ' ';
            continue;
        }
        if (s[i] == ig[j]){
            hold += s[i];
            j++;
        }else if (s[i] == ig[0]){
            if (j){
                res += hold;
                j = 1;
                hold = s[i];
            }
        }
        else{
            if (j)
                res += hold;
            res += s[i];
            hold = "";
            j = 0;
        }
        i++;
    }
    if (j < 3)
        res += hold;
    cout << res;
    return 0;
}

