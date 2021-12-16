#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> smallestDifference(vector<int> arr, vector<int> brr) {
	
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	
	int x, y;
	int curr = INT_MAX;
	int small = INT_MAX;
	int i = 0, j = 0;
	vector<int> stored;
	
	while (i < arr.size() && j < brr.size()){
		x = arr[i];
		y = brr[j];
		if (x < y){
			curr = y - x;
			i++;
		}else if (x > y){
			curr = x - y;
			j++;
		}else{
			return vector<int>{x, y};
		}
		if (small > curr){
			stored = {x, y};
			small = curr;
		}
	}
  return stored;
}
