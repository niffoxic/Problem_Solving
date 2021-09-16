#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> arr, int mov) {
  int i = 0, j = arr.size() - 1;
	
	while (i < j){
		if (arr[i] == mov && arr[j] != mov){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else{
			if (arr[i] != mov)
			{
				i++;
			}
			if (arr[j] == mov)\
			{
				j--;
			}
		}
	}
  return arr;
}
