#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> arr, int s) {
  sort(arr.begin(), arr.end());
	int i = 0, j = arr.size() - 1;
	
	while(i < j){
		if (arr[i] + arr[j] == s){
			return vector<int> {arr[i], arr[j]};
		}else if (arr[i] + arr[j] > s){
			j--;
		}else{
			i++;
		}
	}
	
  return {};
}
