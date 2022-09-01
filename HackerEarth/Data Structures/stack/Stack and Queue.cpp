#include <iostream>
using namespace std;
using ll = long long;


int main() {
	ll n, k, res = 0; cin >> n >> k;
	ll arr[n + 1];

	for(int i = 0; i < n; i++) cin >> arr[i];
	
	ll prefix[n + 1];
	prefix[0] = arr[0];
	
	for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];

	for(int i = 0; i < k; i++){
		ll temp = prefix[i] + prefix[n - 1] - prefix[n - k + i];
		res = max(res, temp);
	}
	return cout << res, 0;
}








