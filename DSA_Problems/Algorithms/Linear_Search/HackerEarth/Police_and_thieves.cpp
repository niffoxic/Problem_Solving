void solve(int case_no)
{
    int n, k; cin >> n >> k;
    int res = 0;
    int grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char per; cin >> per;
            if (per == 'P') grid[i][j] = 1;
            else grid[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (grid[i][j] == 1){
                for (int l = max(0, j - k); l < min(n, k + j + 1); l++){
                    if (grid[i][l] == -1){
                        grid[i][l] += 1;
                        grid[i][j] = 2;
                        res++;
                        break;
                    }
                }
            }

        }
    }

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << grid[i][j] << " ";
//        }
//        cout << nn;
//    }

    print(res)
}
