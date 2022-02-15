#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, x, y; cin >> n >> x >> y;
		unordered_map<int, int> mp;
		for(int i = 0; i < n; i++){
			int k; cin >> k;
			mp[(k & x) ^ (k & y)]++;
		}
		int res = 0;
		for(int i = 0; i < n; i++){
			int k; cin >> k;
			res += mp[(k & x) ^ (k & y)];
		}
		cout << res << "\n";
	}
	return 0;
}
