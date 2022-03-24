#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, left = 0, right = people.size() - 1;
        sort(people.begin(), people.end());
        while (left <= right){
            if (people[left] + people[right] <= limit) left++, right--;
            else right--;
            res++;
        }
        return res;
    }
};

int main(){
    Solution ob;
    vector<int> arr{3, 8, 7, 1, 4};
    cout << ob.numRescueBoats(arr, 9);
    return 0;
}
