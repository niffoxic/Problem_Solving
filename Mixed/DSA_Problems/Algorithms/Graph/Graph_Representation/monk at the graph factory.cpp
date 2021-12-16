#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int c = 0;
	for(int i = 0; i < n; i++){
		int t; cin >> t;
		c += t;
	}
	cout << ((n * 2 - 2 == c)? "Yes" : "No") << endl; 
	return 0;
}
