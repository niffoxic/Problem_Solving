#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        if (n % 4 == 3){
            cout << 0 << "\n";
        }else if (n % 4 == 0){
            cout << 1 << " " << n << "\n";
        }else if (n % 4 == 1){
            cout << 1 << " " << n << "\n";
        }else if (n % 4 == 2){
            cout << 2 << " " << n << " " << n - 1 << "\n";
        }

    }
    return 0;
}
