class Solution
{   
public:
    long long smallestpositive(vector<long long> arr, int n)
    {
        sort(arr.begin(), arr.end());
        long long res = 1, temp = 0;
        for(int i = 0; i < n; i++){
            if (arr[i] <= res){
                temp += arr[i];
                res = temp + 1;
            }else return res;
        }
        return res;
    } 
};
