#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int brokenCalc(int sv, int target){
        int res = 0;
        while(target > sv){
            res++;
            if (!(target & 1)) target >>= 1;
            else target++;
        }
        res += (sv - target);
        return res;
    }
};

int main() {
    return 0;
}
