using namespace std;

int longestPeak(vector<int> arr) {
  int i = 1;
	int peak_length = 0;
	
	while(i < int(arr.size() - 1)){
		bool ispeak = arr[i - 1] < arr[i] && arr[i] > arr[i + 1];
		if (!ispeak){
			i++;
			continue;
		}
		
		int left = i - 2;
		while(left >= 0 && arr[left] < arr[left + 1]){
			left--;
		}
		int right = i + 2;
		while(right < arr.size() && arr[right] < arr[right - 1]){
			right++;
		}
		int res = right - left - 1;
		peak_length = max(peak_length, res);
		i = right;
	}
  return peak_length;
}
