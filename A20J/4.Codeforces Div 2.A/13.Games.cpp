#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int home[101] = {0}, guest[100] = {0};
    while(n--){
        int hi, ai; cin >> hi >> ai;
        home[hi]++, guest[ai]++;
    }
    int res = 0;
    for(int i = 0; i < 101; i++)
        res += home[i] * guest[i];
    cout << res << "\n";
    return 0;
}
