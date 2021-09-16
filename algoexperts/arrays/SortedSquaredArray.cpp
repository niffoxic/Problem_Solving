#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquaredArray(vector<int> arr) {
  vector<int> res;
	
	for(int i = 0; i < arr.size(); ++i){
		res.push_back(arr[i]*arr[i]);
	}
	sort(res.begin(), res.end());
  return res;
}
