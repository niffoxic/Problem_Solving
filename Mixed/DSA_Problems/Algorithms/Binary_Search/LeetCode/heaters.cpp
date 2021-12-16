class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        int m =  heaters.size();
        sort(heaters.begin(), heaters.end());
        int res = INT_MIN;

        for(int i = 0; i < n; i++){
            int left = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int right = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();

            if (left < m && heaters[left] == houses[i])
                res = max(res, 0);
            else{
                int ls = (left - 1 >= 0)? houses[i] - heaters[left - 1]: INT_MAX;
                int rs = (right < m)? heaters[right] - houses[i]:INT_MAX;
                res = max(res, min(ls, rs));
            }
        }
        return res;
    }
};
