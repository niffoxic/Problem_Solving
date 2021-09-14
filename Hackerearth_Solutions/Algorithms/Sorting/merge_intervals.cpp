class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if (intervals[intervals.size() - 1][0] <= end){
            res.push_back({start, max(end, intervals[intervals.size() - 1][1])});
        }
        return res;
    }
};
