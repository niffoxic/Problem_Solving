class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        string res;
        int i = 0, j = 0;
        while (i < s.size() && j < spaces.size()){
            if (i == spaces[j]){
                res += ' ';
                j++;
                continue;
            }
            res += s[i];
            i++;
        }
        while (i < s.size()){
            res += s[i];
            i++;
        }
        return res;
    }
};
