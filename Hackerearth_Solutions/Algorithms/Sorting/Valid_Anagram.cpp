class Solution {
public:
    bool isAnagram(string s, string t) {
        int res[26] = {0};
        if (s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            res[s[i] - 'a']++;
            res[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) if (res[i] != 0) return false;
        return true;
    }
};
