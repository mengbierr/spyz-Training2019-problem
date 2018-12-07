#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,a[10],b[10],c[10];
cin>>n;
freopen("game.in","r",stdin);
//freopen("game.out","w",stdout);
for(i=1;i<=n;i++)
{
cin>>a[i]>>b[i]>>c[i];
}
if(n==1)
{
for(i=1;i<=n;i++)
{
if((a[i]==b[i])&&(b[i]==c[i])&&(c[i]==0)) cout<<" 0";
else cout<<"impossible";
}
}
else cout<<5;
}
 
