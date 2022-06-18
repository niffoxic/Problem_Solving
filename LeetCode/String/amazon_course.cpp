#include <bits/stdc++.h>

using namespace std;

string lexicographicallySmallest(int input1, string input2) {
    string kev;
    stack<char> ben;
    int freq[26];
    for (int i = 0; i < 26; i++) freq[i] = 0;

    int left_pointer = 26;
    for (int i = 0; i < input1; i++)
        freq[input2[i] - 'a']++, left_pointer = min(left_pointer, input2[i] - 'a');

    int i = 0;
    while (i < input1) {
        if (left_pointer == input2[i] - 'a') {
            kev.push_back(input2[i]);
            freq[left_pointer]--;
            while (left_pointer < 26 && !freq[left_pointer]) left_pointer++;
            while (!ben.empty() && left_pointer >= ben.top() - 'a') kev.push_back(ben.top()), ben.pop();
        } else ben.push(input2[i]);
        i++;
    }
    while (!ben.empty()) kev.push_back(ben.top()), ben.pop();
    return kev;
}


int main() {
    string s = "abnmz";
    return cout << lexicographicallySmallest(5, s), 0;
}
