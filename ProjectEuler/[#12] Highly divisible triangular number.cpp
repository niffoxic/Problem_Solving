#include <bits/stdc++.h>
using namespace std;


#define template_size 502
using ull = unsigned long long;

int main() {
    std::vector<unsigned int> res;
    res.push_back(0);
    ull currentNumber = 0;
    ull naturalSum = 0;
    while (res.size() < template_size) {
        currentNumber++;
        naturalSum += currentNumber;
        ull totalDivisors = 0;
        ull i = 1;
        while (i * i < naturalSum) {
            if (naturalSum % i == 0)
                totalDivisors += 2;
            i++;
        }
        if (i * i == naturalSum)
            totalDivisors++;
        while (res.size() <= totalDivisors)
            res.push_back(naturalSum);
    }
    cout << res[template_size] << endl;
    return 0;
}
