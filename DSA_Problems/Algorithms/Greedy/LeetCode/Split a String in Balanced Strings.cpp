class Solution {
public:
    int balancedStringSplit(string& s1) {
        int res = 0;
        int cnt = 0;
        for(char i : s1){
            if (i == 'R') cnt++;
            else cnt--;
            if (!cnt) res++;
        }
        return res;
    }
};
