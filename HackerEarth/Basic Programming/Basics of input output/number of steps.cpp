#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int arr[n], brr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) cin >> brr[i];
    int min = arr[0];
    for(int i = 0; i < n; ++i){
        min = (min > arr[i])? arr[i] - brr[i]: min;
    }
    int counts = 0;
    for(int i = 0; i < n; ++i){
        while(min < arr[i] && brr[i] != 0){
            arr[i] = arr[i] - brr[i];
            counts++;
        }
 
        if (arr[i] != min){
            counts = -1;
            break;
        }
    }
    return cout << counts, 0;
}
