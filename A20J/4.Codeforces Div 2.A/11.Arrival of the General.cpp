#include<bits/stdc++.h>

itn main(){
  int n,i,p,q=99,x,a,b;
  for(std::cin>>n; i++<n;)
  std::cin>>x,x>p?p=x,b=i:0,x<=q?q=x,a=i:0;
  std::cout<<b+n-a-1-(b>a);
}
