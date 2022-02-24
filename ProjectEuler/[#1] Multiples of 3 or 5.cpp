// O(1) time

ll get(int val){
    int res = 999 / val;
    return val * res * (res + 1) / 2;
}

void solve(int case_no) {
    cout << get(3) + get(5) - get(15);
}
