#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if (i > 0) arr[i] += arr[i - 1];
	}
	int q; cin >> q;
	while(q--){
		int left, right;
		cin >> left >> right;
		if (!left) cout << arr[right] << "\n";
		else cout << arr[right] - arr[left - 1] << "\n";
	}
	return 0;
}
