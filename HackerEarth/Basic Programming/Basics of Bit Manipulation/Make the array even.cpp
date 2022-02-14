#include <iostream>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
 
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i <n;i++) cin >> arr[i];
        int res = 0;
        int other = 0;
        int i = 0;
        while (i < n){
            int hmm = false;
            if (arr[i] %2 != 0 && arr[i+1] %2 !=0){
                res++;
                i+=2;
                hmm = true;
            }else if (arr[i]%2 !=0 && arr[i + 1]%2 ==0){
                other += 2;
                i++;
                hmm = true;
            }
            if(!hmm){
                i++;
            }
        }
        cout << res + other << "\n";
    }
 
}
