#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> arr) {
  vector<int> res(arr.size(), 1);
	
	int left = 1;
	int right = 1;
	
	for(int i = 0; i < arr.size(); ++i){
		res[i] = left;
		left *= arr[i];
	}
	
	for(int i = arr.size() - 1; i >= 0; --i){
		res[i] *= right;
		right *= arr[i];
	}
  return res;
}
