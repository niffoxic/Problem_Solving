class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> res(bank.size(), 0);
        for(auto &i: bank){
            int curr = 0;
            for(auto j: i)
                curr += (j == '1')?1: 0;
            if (curr)
                res.push_back(curr);
        }
        int ans = 0;
        for(int i = 0; i < res.size() - 1; i++)
            ans += res[i] * res[i + 1];
        return ans;
    }
};
