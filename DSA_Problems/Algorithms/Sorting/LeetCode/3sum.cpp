// Solution 1

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<string> occ;
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            int left = i + 1, right = nums.size() - 1;
            int total = 0;
            while(left < right){
                total = nums[i] + nums[left] + nums[right];
                if (total == 0){
                    string current = to_string(nums[i]) + to_string(nums[left]) + to_string(nums[right]);
                    if (occ.find(current) == occ.end()){
                        occ.insert(current);
                        res.push_back({nums[i], nums[left], nums[right]});
                    }
                    left++; right--;
                }else if (total > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};


// Solution 2

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> occu;
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            int left = i + 1, right = nums.size() - 1;
            int total = 0;
            while(left < right){
                total = nums[i] + nums[left] + nums[right];
                if (total == 0){
                    if (occu.find({nums[i], nums[left], nums[right]}) == occu.end()) {
                        res.push_back({nums[i], nums[left], nums[right]});
                        occu.insert({nums[i], nums[left], nums[right]});
                    }
                    left++; right--;
                }else if (total > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};

// Solution 3

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1, right = nums.size() - 1;
            int total = 0;
            while(left < right){
                total = nums[i] + nums[left] + nums[right];
                if (total == 0){
                    res.insert({nums[i], nums[left], nums[right]});
                    left++; right--;
                }else if (total > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i: res) ans.push_back(i);
        return ans;
    }
};

// Solution 4

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size()<3) return {};

    sort(nums.begin(),nums.end());
    vector<vector<int>> ans ;

    if(nums.size()==3) {
        if(nums[0]+nums[1]== - nums[2]) {
            ans.push_back(nums);
        }
        return ans;
    }

    for(int i=0; i<=nums.size()-3; ++i) {
        if(nums[i]>0) break;
        int target = -nums[i];
        int left=i+1,right=nums.size()-1;

        while(left<right) {
            int two = nums[left]+nums[right];

            if(two<target) {
                ++left;
            }
            else if(two>target) {
                --right;
            }
            else {
                int s1 = nums[left],s2 = nums[right];
                ans.push_back({-target,s1,s2});
                while(nums[left] == s1 && left<right) ++left;
                while(nums[right] == s2 && left<right) --right;
            }
        }
        while(i+1<left) {
            if(nums[i+1] == -target)++i;
            else break;
        }
    }
    return ans;
    }
};
