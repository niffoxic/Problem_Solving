#include <bits/stdc++.h>
using namespace std;

template <class T>
T naturalSquare(T _n){
    return (_n * (_n + 1) * (2 * _n + 1)) / 6;
}

template <class T>
T naturalSum(T _n){
    return (_n * (_n + 1)) / 2;
}

int main(){
    cout << naturalSum(100) * naturalSum(100) - naturalSquare(100);
    return 0;
}
