class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double>weight(n, 0);
        for(int i = 0; i < n; i++){
            int current = (int)ceil((double)dist[i] / speed[i]);
            if (current < n)
                weight[current]++;
        }
        int res = 0;
        for(int i = 1; i < n; i++){
            res += weight[i];
            if (res > i) return i;
        }
        return n;
    }
};
