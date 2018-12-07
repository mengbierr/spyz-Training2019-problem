#include<bits/stdc++.h>
using namespace std;
int main()
{
double  n,a[1001],x,y=0,s=0,c,d;
int i;
//freopen("sabotage.in","r",stdin);
//freopen("sabotage.out","w",stdout);
cin>>n;
d=n;
for(i=1;i<=n;i++)
{
cin>>a[i];
y=y+a[i];
if(a[i]>=s) (s=a[i],x=i);

else s=s;
}
c=y/n;
for(i=x;i<n;i++)

{
 if((y-a[i])/n<c) (a[i]=0.000,n--);
else break;
}
for(i=x-1;i>=1;i--)
{

 if((y-a[i])/n<c) (a[i]=0.000,n--);
else break;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
y=0;
for(i=1;i<=d;i++)
{
y=y+a[i];
}
y=y/n;
printf("%.3lf",y);
}
