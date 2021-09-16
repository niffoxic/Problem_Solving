#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> arr, int targetSum) {
  // Write your code here.
	vector<vector<int>> res;
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < arr.size() - 1; ++i){
		for(int j = i + 1; j < arr.size(); ++j){
			int left = j + 1;
			int right = arr.size() - 1;
			while(left < right && left < arr.size()){
				int current = arr[i] + arr[j] + arr[left] + arr[right];
				if (current == targetSum){
					res.push_back({arr[i], arr[j], arr[left], arr[right]});
					right--;
					left++;
				}
				else if (current > targetSum){
					right--;
				}else{
					left++;
				}
			}
		}
	}
  return res;
}
