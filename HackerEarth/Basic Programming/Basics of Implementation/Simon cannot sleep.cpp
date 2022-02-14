#include <iostream>
 
using namespace std;
 
int main(){
    string s; cin >> s;
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, s.size()));
    // 6 per min, 1/2 per hour
    // ang = 6 - 1/2 = 12 - 1/ 2 = 11 / 2
    // 360 / (11 / 2) =  720 / 11
    cout << ((hour * 60 + min) * 11) / 720 + 1 << "\n";
    return 0;
}
