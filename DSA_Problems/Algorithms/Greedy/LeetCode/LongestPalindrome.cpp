class Solution {
public:
    int longestPalindrome(string& s1) {
        unordered_map<char, int> charMap;
        for(char i : s1) charMap[i]++;
        int res = 0, odd = 0;
        for(auto i : charMap){
            if (i.second & 1){
                res += (i.second - 1);
                if (!odd) odd = 1;
            }
            else res += i.second;
        }
        return res + odd;
    }
};
