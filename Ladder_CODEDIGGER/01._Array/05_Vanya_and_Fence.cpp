

 
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n, h;
        cin >> n >> h;
        int res = 0;
        for(int i = 0; i < n; i ++){
            int fn; cin >> fn;
            res += (h >= fn)?1:2;
        }
        print(res)
    }
    return 0;
}
 
 
 
