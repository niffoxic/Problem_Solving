#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int n, int left, int right, vector<string>& container, string res) {
        if (left == right && right == n) {
            container.push_back(res);
            return;
        }
        if (left < n)
            solve(n, left + 1, right, container, res + '(');
        if (right < left)
            solve(n, left, right + 1, container, res + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, 0, 0, res, "");
        return res;
    }
};

int main() {
    // test case 1.
    int n = 3;
    Solution ob;
    vector<string> check;
    check = ob.generateParenthesis(n);
    for (auto i : check)
        cout << i << "\n";
	return 0;
}
