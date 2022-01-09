#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,v,x,k,ans=0,f=1;
    vector<int> d;
    cin>>n>>v;
    for(int i = 0;i < n;i++){
        cin>>k;
        for(int j = 0;j < k;j++){
            cin>>x;
            if(f && x < v){
                ans++;
                d.push_back(i+1);
                f = 0;
            }
        }
        f=1;
    }
    cout<<ans<<endl;
    for(int i : d) cout<<i<<" ";
    return 0;
}
