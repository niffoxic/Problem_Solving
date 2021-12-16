int CountWays(string a){
	unsigned long long int n = a.length();
	unsigned long long int dp[n];
	const int mod = 1e9+7;
	
	
	dp[0] = 1;
	if (a[0] == '0') return 0;
	
	
	for(int i = 1; i < n; i++){
		if (a[i - 1] == '0' && a[i] == '0'){
		    dp[i] = 0;
		}else if (a[i - 1] == '0' && a[i] != '0'){
		    dp[i] = dp[i - 1];
		}else if (a[i - 1] != '0' && a[i] == '0'){
		    int asci = a[i - 1] - '0';
		    if (asci * 10 < 21) dp[i] = (i >= 2)?dp[i - 2]: 1;
		    else dp[i] = 0;
		}else{
		    dp[i] = dp[i - 1];
		    int counts = (a[i - 1] - '0') * 10 + (a[i] - '0');
		    if (counts <= 26) dp[i] += (i >= 2)?dp[i - 2]: 1;
		    dp[i] %= mod;
		}
		dp[i] %= mod;
	}
	
	
	return dp[n - 1] % mod;
}
