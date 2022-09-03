
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        vector<int> temp(9,0); vector<vector<int>> v(9,temp); v[a][b]=1;
        if(a == 1 && b == 1) v[3][2] = 2;
        else if(a==1 && b == 8) v[3][7] = 2;
        else if(a == 8 && b == 1) v[7][3]=2;
        else if(a==8&&b==8) v[6][7]=2;
        else if(a==8) v[6][b-1]=2, v[6][b+1]=2;
        else if(a==1) v[3][b-1]=2, v[3][b+1]=2;
        else if(b==1) v[a-1][3]=2, v[a+1][3]=2;
        else if(b==8) v[a-1][6]=2,v[a+1][6]=2;
        else {

            if(b>2&&b<7)
            {
            v[a-1][b+2]=2;
            v[a+1][b-2]=2;
            }
            else if(a>2&&a<7)
            {
            v[a+2][b-1]=2;
            v[a-2][b+1]=2;
            }
            else {
            if(a==2&&b==2)
            {
                v[1][4]=2;
                v[5][1]=2;
            }
            else if(a==2&&b==7)
            {
                v[1][5]=2;
                v[5][8]=2;
            }
            else if(a==7&&b==2)
            {
                v[8][5]=2;
                v[5][1]=2;
            }
            else if(a==7&&b==7)
            {
                v[4][8]=2;
                v[8][5]=2;
                
            }
            else if(a>2&&a<7)
            {
                v[a-2][b-1]=2;
                v[a+2][b+1]=2;
            }
            else
            {
                v[a+1][b-2]=2;
                v[a-1][b+2]=2;
            }
            }
        }

    for(int l=1;l<=8;l++)
    {
        for(int i=1;i<=8;i++) cout<<v[l][i]<<" ";
        cout<<endl;
    }
}
    return 0;
}