class Solution {
public:
    string repeatLimitedString(string& s, int repeatLimit) {
        int mp[26] = {0}, i;
        string res;
        for (char c : s) mp[c - 'a']++;
        int prev = -1, cnt = 0;
        while (true) {
            i = 25;
            while (i >= 0 && (mp[i] == 0 || (cnt == repeatLimit && prev == i))) i--;
            if (i >= 0) {
                res.push_back('a' + i);
                mp[i]--;
                cnt = prev == i ? cnt + 1 : 1;
                prev = i;
            } else break;
        }
        return res;
    }
};
