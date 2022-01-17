#include <bits/stdc++.h>
using namespace std;


int main(){
    string s; cin >> s;
    unsigned long long mid = 0, left = 0, right = 0, switched = 0;
    for(int i = 0; i < s.size() && !mid; i++)
        if (s[i] == '^') mid = i;
    int i = 0;
    while (i < s.size())
    {
        if (!switched)
        {
            left += s[i] != '='?mid * (s[i] - '0'): 0;
            mid--;
        }else
        {
            mid++;
            right += s[i] != '='?mid * (s[i] - '0'): 0;
        }
        if (mid == 0){
            switched = 1;
            i++;
        }
        i++;
    }
    return cout << (left == right? "balance": left > right?"left": "right"), 0;
}
