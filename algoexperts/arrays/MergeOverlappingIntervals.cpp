#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return a[0] < b[0]; });
	vector<vector<int>> res;
	int start = intervals[0][0];
	int end = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++){
		if (end >= intervals[i][0] && start <= intervals[i][1]){
			end = max(end, intervals[i][1]);
			start = min(start, intervals[i][0]);
		}else{
			res.push_back({start, end});
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	res.push_back({start, end});
  return res;
}
