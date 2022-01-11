#include<bits/stdc++.h>
using namespace std;


int main(){
    int a, b; cin >> a >> b;
    int f = 0, d = 0;
    for(int i = 1; i <= 6; i++){
        if(abs(i - a) < abs(i - b)) f++;
        else if (abs(i - a) == abs(i - b)) d++;
    }
    cout << f << " " << d << " " << 6 - f - d;
    return 0;
}
