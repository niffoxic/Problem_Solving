class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
void convert(int arr[], int n) {
    vector<vector<int>> res;
    for(int i = 0; i < n; i++)
        res.push_back({arr[i], i});
    sort(res.begin(), res.end());
    for(int i = 0; i < n; i++)
        arr[res[i][1]] = i;
}

};
