#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n=0,h=0,i,j;
    cin>>t;
    int a[t];
    for(i=0;i<t;i++)
    {
        cin>>a[i];
        h+=a[i];
    }
    sort(a,a+t);
    for(i=0;2*n<=h;i++)
        n+=a[t-i-1];

    cout<<i<<endl;
}
