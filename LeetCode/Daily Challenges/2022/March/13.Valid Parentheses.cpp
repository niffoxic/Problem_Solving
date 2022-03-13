#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isValid(string &s) {
        stack<char> res;
        for (auto i: s) {
            if (i == '(' || i == '{' || i == '[') res.push(i);
            else {
                if (res.empty() || (res.top() == '(' && i != ')') || (res.top() == '{' && i != '}') ||
                    (res.top() == '[' && i != ']'))
                    return false;
                res.pop();
            }
        }
        return res.empty();
    }
};
