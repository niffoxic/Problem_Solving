

int main()
{
    //  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        ll n; cin >> n;
        uml res;
        int val = 1;
        ll arr[n];
        for(int i = 0; i < n; i++){
            ll current; cin >> current;
            arr[i] = current;

            if (i > 0 && arr[i] != arr[i - 1] && res.find(current) != res.end()) val = 0;

            if(res.find(current) == res.end()) res[current] = 1;
            else res[current]++;

        }
        if (val){
            unordered_set<ll> ans;
            for(auto i: res){
                if (ans.find(i.second) != ans.end()){
                    val = 0;
                    break;
                }
                ans.insert(i.second);
            }
        }
        cout << (val?YES:NO) << nn;
    }

    return 0;
}

