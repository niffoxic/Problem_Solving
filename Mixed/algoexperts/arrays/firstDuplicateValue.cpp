#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> arr)
{
	for(auto i: arr){
		int abs_val = abs(i);
		if (arr[abs_val - 1] < 0){
			return abs_val;
		}
		arr[abs_val - 1] *= -1;
	}
	return -1;
}
