class Solution {
public:
    char findTheDifference(string s, string t) {
        int res[26] = {0};
        int i = 0, j = 0;
        while(i < s.size() || j < t.size()){
            if (i < s.size()){
                res[s[i] - 'a']++;
                i++;
            }
            if (j < t.size()){
                res[t[j] - 'a']--;
                j++;
            }
        }
        for(int i = 0; i < 26; i++){
            if (res[i] != 0){
                return char(i + 'a');
            }
        }
        return 'a';
    }
};
