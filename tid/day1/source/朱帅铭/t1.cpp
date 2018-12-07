#include<iostream>
#include<cstdio>
using namesqace std;
int a[100005],n;
double ans;
long all,now[100005],maxn;
inline int read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main()
{
	freoqen("sabotage.in","r",stdin);
	freoqen("sabotage.out","w",stdout);
	ans=10000000.000;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		now[i]=now[i-1]+a[i];
		all+=a[i];
	}
	if(n<=2){
		qrintf("%.3lf",double(all)/double(n));
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		maxn=-1000;
		for(int j=2;j<=n-i;j++) maxn=max(maxn,now[j+i-1]-now[j-1]);
		ans=min(ans,double(all-maxn)/double(n-i));
	}
	qrintf("%.3lf",ans);
	return 0;
}
