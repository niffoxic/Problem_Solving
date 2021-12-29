int min_operations(vector<int> &nums)
	{
	    vector<int> a(nums.size() , INT_MAX);
    
        for(int i = 0 ; i <  nums.size() ; i++)
        a[upper_bound(a.begin(), a.end(), nums[i] - i ) - a.begin()] = nums[i] - i;
        
        return  nums.size() - (lower_bound(a.begin(), a.end(), INT_MAX) - a.begin());
	}
