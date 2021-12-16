class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> prizes = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> res;
        for(int i = 0; i < score.size(); i++){
            res.emplace_back(score[i], i);
        }
        sort(res.begin(), res.end());
        vector<string> ans(score.size());
        int i = 0;
        while(i < 3 && i < score.size()){
            ans[res[score.size() - 1 - i].second] = prizes[i];
            i++;
        }
        i++;
        int temp = i;
        for(int j = score.size() - temp; j >= 0; j--){
            ans[res[j].second] = to_string(i);
            i++;
        }
        return ans;
    }
};
