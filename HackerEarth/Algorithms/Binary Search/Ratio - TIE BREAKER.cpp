#include <bits/stdc++.h>
using namespace std;

#define abs(x) ( (x)<0 ? -1*(x) : (x) )


double Sum_ratio(const vector<vector<double>> &arr, const double &R) {
    double sum = 0;
    for (auto i: arr)
        sum += i[0] / (i[1] + R);
    return sum;
}

double Solve(const vector<vector<double>> &arr, int N, double K) {
    double min_R = arr[0][1], max_R, R, sum;
    for (auto i: arr)
        if (i[1] < min_R)
            min_R = i[1];
    R = ((min_R <= 0) ? (1.00 - min_R) : min_R);
    min_R = 1.0 - min_R;
    while (true) {
        sum = Sum_ratio(arr, R);
        if (abs(sum - K) <= 1e-6)
            break;
        else if (sum > K) {
            min_R = R;
            R = R * 2;
        } else {
            while (true) {
                sum = Sum_ratio(arr, R);
                if (abs(sum - K) <= 1e-6)
                    break;
                else if (sum > K) {
                    min_R = R;
                    R = (max_R + R) / 2;
                } else {
                    max_R = R;
                    R = (min_R + R) / 2;
                }
            }
            break;
        }
    }
    return R;
}


int main() {
    int N, col;
    double K;
    cin >> N >> col;
    vector<vector<double>> arr(N, vector<double>(2));
    for (auto &i: arr)
        cin >> i[0] >> i[1];
    cin >> K;
    cout << setprecision(15) << Solve(arr, N, K);
    return 0;
}
