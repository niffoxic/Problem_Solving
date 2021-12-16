class Solution {
public:
    int maxNumberOfBalloons(string& text) {
        int res[26] = {0};
        for(auto i: text){
            res[i - 'a']++;
        }
        string tar = "balloon";
        res['l' - 'a'] = res['l' - 'a'] / 2;
        res['o' - 'a'] = res['o' - 'a'] / 2;
        int ans = INT_MAX;
        for(auto i: tar){
            ans = min(ans, res[i - 'a']);
        }
        return ans == INT_MAX?0: ans;
    }
};
