#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,cnt,tot;
double ans;
struct P
{
    double x,y;
}p[100005],a[100005];
struct L
{
    P a,b;
    double slop;
}l[100005],q[100005];
P operator -(P a,P b)
{
    P t;t.x=a.x-b.x;t.y=a.y-b.y;
    return t;
}
double operator *(P a,P b)
{
    return a.x*b.y-a.y*b.x;
}
void getans()
{
    if(tot<3) return;
    a[++tot]=a[1];
    for(int i=1;i<=tot;i++)
    {
		ans+=a[i]*a[i+1];
		//cout<<ans<<endl;
	}
	//cout<<ans<<endl;
    ans=fabs(ans)/2;
}
int main()
{
	//freopen("gift10.in","r",stdin);
	//freopen("gift10.out","w",stdout);
    n=read();
    tot=n;
    for(int i=1;i<=n;i++)
    {
    	a[i].x=read();a[i].y=read();
	}
	getans();
    printf("%.3lf",ans);
}
