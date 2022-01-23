class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string& str, int n)
    {
        string small, cap, res;
        for(auto i: str){
            if (i < 91) cap += i; else small += i;
        }
        sort(small.begin(), small.end()), sort(cap.begin(), cap.end());
        int i = 0, j = 0, k = 0;
        while (k < n)
        {
            if (str[k] < 91)
                res += cap[i++];
            else res += small[j++];
            k++;
        }
        return res;
    }
};
