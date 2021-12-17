class Solution {
public:
    double average(vector<int>& salary)
    {
        int res = 0;
        int mx = salary[0], mn = salary[0];
        for(auto i: salary){
            if (mx < i) mx = i;
            if (mx != i && mn > i) mn = i;
            res+=i;
        }
        return (double)(res - mx - mn) / (salary.size() - 2);
    }
};
