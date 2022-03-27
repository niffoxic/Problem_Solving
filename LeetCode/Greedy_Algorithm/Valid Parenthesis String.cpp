#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string& s) {
        stack<int> left, right; int n = s.size();
        for(int i = 0; i < n; i++){
            if (s[i] == '(') left.push(i);
            else if (s[i] == '*') right.push(i);
            else{
                if (!left.empty()) left.pop();
                else if (!right.empty()) right.pop();
                else return false;
            }
        }
        while (!left.empty()){
            if (right.empty()) return false;
            if (left.top() < right.top()) left.pop(), right.pop();
            else return false;
        }
        return true;
    }
};
