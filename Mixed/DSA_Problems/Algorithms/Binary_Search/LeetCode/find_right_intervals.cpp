class Solution {
public:

    int bin_search(vector<vector<int>>& intervals, int left, int selected){
        int right = (int)intervals.size() - 1;
        int res = -1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if (intervals[mid][0] >= selected){
                res = mid;
                right = mid - 1;
            }else
                left = mid + 1;
        }
        return res == -1?-1:intervals[res][2];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for(int i = 0; i < intervals.size(); i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> res;
        for(int i = 0; i < intervals.size(); i++) res.push_back(-1);
        for(int i = 0; i < intervals.size() - 1; i++){
            int current = bin_search(intervals, i, intervals[i][1]);
            res[intervals[i][2]] = current;
            cout << current << endl;
        }
        return res;
    }
};
