using namespace std;

bool isMonotonic(vector<int> arr) {
	bool inc = true;
	bool dec = true;
	for(int i = 1; i < arr.size(); ++i){
		if (arr[i] < arr[i - 1]){
			inc = false;
		}
		if(arr[i] > arr[i - 1]){
			dec = false;
		}
	}
  return inc || dec;
}
