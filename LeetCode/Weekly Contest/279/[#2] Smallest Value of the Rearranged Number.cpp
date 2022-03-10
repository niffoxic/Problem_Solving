#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long smallestNumber(long long num) {
        int digit[10] = {0};
        if (num < 0){
            num *= -1;
            string res = to_string(num);
            sort(res.begin(), res.end(), greater<>());
            return -1LL * stoll(res);
        }
        string t = to_string(num);
        for(char i : t) digit[i - '0']++;
        int left = 1;
        while (left < 10 && !digit[left]) left++;
        if (left == 10) return 0;
        using ll = long long;
        string res = to_string(left); digit[left]--;
        for(int i = 0; i < 10; i++){
            while (digit[i]--){
                res += to_string(i);
            }
        }
        return stoll(res);
    }
};
