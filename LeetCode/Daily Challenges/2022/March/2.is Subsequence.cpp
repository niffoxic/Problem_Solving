class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int left = 0, n = s.size();
        for(int i = 0; i < t.size(); i++){
            if (left < n && s[left] == t[i]) left++;
        }
        return left == n;
    }
};
