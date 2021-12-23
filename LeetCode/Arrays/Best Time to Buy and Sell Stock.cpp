
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = -1, res = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[left])
                left = i;
            if (right == -1 || (prices[right] < prices[i] || left > right))
                right = i;
            if (left < right)
                res = max(res, prices[right] - prices[left]);
        }
        return res;
    }
};
