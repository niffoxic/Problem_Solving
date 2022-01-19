class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = prices.size();
        long long current = 0;
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] == prices[i + 1] + 1)
                current++;
            else{
                res += (current * (current + 1)) / 2;
                current = 0;
            }
        }
        if (current)
            res += (current * (current + 1)) / 2;
        return res;
    }
};
