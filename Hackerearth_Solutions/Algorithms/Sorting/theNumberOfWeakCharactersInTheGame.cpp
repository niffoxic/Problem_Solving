class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const auto &a, const auto &b){
            return a[0] == b[0]? a[1] < b[1] : a[0] > b[0];
        });
        int res = 0, md = INT_MIN;
        for(auto &i: properties){
            res += i[1] < md;
            md = max(md, i[1]);
        }
        return res;
    }
};
