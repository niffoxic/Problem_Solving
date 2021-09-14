// Lomuto easy 
class Solution {
private:

    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i = left, j = left - 1;
        while(i <= right){
            if (nums[i] <= pivot){
                j++;
                swap(nums[i], nums[j]);
            }
            i++;
        }
        swap(nums[left], nums[j]);
        return j;
    }

    int ans(vector<int>& nums, int left, int right, int needed_index){
        if (left == right) return nums[left];
        int p = partition(nums, left, right);
        if(p == needed_index) return nums[p];
        if (p < needed_index) return ans(nums, p + 1, right, needed_index);
        return ans(nums, left, p - 1, needed_index);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return ans(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
