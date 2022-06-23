class Solution {
public:
    vector<string> res;

    void solve(string &s, string ans, int index, int holder) {
        if (holder > 4) return;
        if (index == s.length() && holder == 4) {
            ans.pop_back();
            res.push_back(ans);
            return;
        }

        int current = 0;
        for (int i = index; i < s.length(); i++) {
            ans += s[i];
            current = current * 10 + s[i] - '0';
            if (current > 255) break;
            if (current == 0) {
                solve(s, ans + '.', i + 1, holder + 1);
                break;
            }
            solve(s, ans + '.', i + 1, holder + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, "", 0, 0);
        return res;
    }
};
