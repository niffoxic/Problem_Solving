using str = string;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while(t--) {
        str qs;
        cin >> qs;

        int selected = 0;
        int res = 1;
        int current = 1;
        for(int i = 1; i < qs.size(); i++)
        {
            if (qs[selected] == qs[i]){
                current++;
                res = max(res, current);
            }else{
                res = max(res, current);
                current = 1;
                selected = i;
            }
        }
        cout << res << "\n";

    }

    return 0;
}
