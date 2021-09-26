class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26] = {0};
        int maxi = 0;
        for(auto i: tasks){
            arr[i - 'A']++;
            maxi = max(maxi, arr[i - 'A']);
        }
        int current = (maxi - 1) * (n + 1);
        for(auto i: arr) if (i == maxi) current++;
        return max(current, (int)tasks.size());
    }
};
