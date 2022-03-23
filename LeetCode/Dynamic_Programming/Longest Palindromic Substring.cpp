class Solution1 {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int len = 1, minIndex = 0;
        for(int iter = 0; iter < n; iter++){
            for(int left = 0, right = iter; left < n && right < n; left++, right++){
                if (iter == 0) dp[left][right] = 1;
                else if (iter == 1) dp[left][right] = s[left] == s[right]? 1: 0;
                else{
                    dp[left][right] = s[left] == s[right] && dp[left + 1][right - 1];
                }
                if (dp[left][right] && abs(right - left) + 1 > len)
                    len = abs(right - left) + 1, minIndex = left;
            }
        }
        return s.substr(minIndex, len);
    }
};


class Solution2 {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        if (s.size() < 1) return s;
        int minIndex = 0, maxLen = 1;
        for(int i = 0; i < n; i++){
            if (n - i <= (maxLen >> 1)) break;
            int left = i, right = i;
            while (right < s.size() - 1 && s[right] == s[right + 1]) right++;
            while (left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) left--, right++;
            int len = right - left + 1;
            if (len > maxLen) minIndex = left, maxLen = len;
        }
        return s.substr(minIndex, maxLen);
    }
};
