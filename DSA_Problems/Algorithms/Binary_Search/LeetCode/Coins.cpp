void solve(int case_no){
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
    int pre[n]; pre[0] = arr[0];
    for(int i = 1; i < n; i++) pre[i] = arr[i] + pre[i - 1];
    int left = 0, right = n - 1;
    bool flag = false;
    while(left < right){
//        cout << pre[left] << " " << pre[right] - pre[left] + arr[left] << nn;
        if (pre[left] == pre[right] - pre[left] + arr[left]){
            flag = true;
            break;
        }else left++;
    }
    cout << (flag?YES:NO) << nn;
}
