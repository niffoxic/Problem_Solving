#include <iostream>
#include <climits>
using namespace std;
 
int get_last_index(int current, int n){
    int counts = 2;
    while (current + counts < n){
        current += counts;
        counts++;
    }
    return current;
}
 
long long get_sum(long long arr[], int left, int right){
    if (left != 0){
        return arr[right] - arr[left - 1];
    }
    return arr[right];
}
 
int main(){
    int n;
    cin >> n;
    int arr[n];
    long long prefix[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    prefix[0] = arr[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    cout << endl;
    long long max_sum = INT_MIN;
    int best_index = 0;
    for (int i = 0; i < n; ++i){
        int index = get_last_index(i, n);
        long long current = 0;
        if (index == i){
            current = arr[i];
        }else{
            current = get_sum(prefix, i, index);
        }
        if (max_sum < current){
            best_index = i;
            max_sum = current;
        }
    }
    return max_sum, 0;
}
