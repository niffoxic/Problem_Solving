class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (!num) return true;
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return s[0] != '0';
    }
};
