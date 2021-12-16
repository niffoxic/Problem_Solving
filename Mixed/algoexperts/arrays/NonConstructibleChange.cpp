#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
	sort(coins.begin(), coins.end());
	int change = 0;
	for(int i = 0; i < coins.size(); ++i){
		if (change + 1 < coins[i]){
			return change + 1;
		}
		change += coins[i];
	}
	
  return change + 1;
}
