class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(make_pair(nums[i], i));
        }
        sort(res.begin(), res.end());
        vector<int> ans(nums.size());
        ans[res[0].second] = 0;
        int counts = 0;
        int temp = 0;
        for(int i = 1; i < nums.size(); i++){
            if (res[i].first == res[i - 1].first){
                ans[res[i].second] = counts;
                temp++;
            }else{
                counts++;
                counts += temp;
                temp = 0;
                ans[res[i].second] = counts;
            }
        }
        return ans;
    }
};

// Solution 2

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> s;
        vector<int> a;
        for(int i=0;i<nums.size();i++)
        {
            a.push_back(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int x = nums.size();
        for(int i=nums.size()-1;i>=0;i--)
        {
            x= x-1;
            s[nums[i]]= x;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]= s[a[i]];
        }
        return nums;
    }
};
