#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> arr, int targetSum) {
  vector<vector<int>> res;
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size(); ++i){
		int left = i + 1;
		int right = arr.size() - 1;
		while (left < right)
		{
			int curr = arr[left] + arr[right] + arr[i];
			if (curr == targetSum){
				res.push_back({arr[i], arr[left], arr[right]});
				left++;
				right--;
			}
			else if(curr > targetSum){
				right--;
			}else{
				left++;
			}
		}
	}
  return res;
}
