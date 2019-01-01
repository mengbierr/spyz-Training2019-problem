#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const double eps=1e-12;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
struct point
{
	double x,y,slop;
	int id;
}p[100005];
int n;
bool cmp1(const point &x,const point &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
bool cmp(const point &x,const point &y)
{
	if(abs(x.slop-y.slop)<eps)
	{
		if(x.x!=y.x)
		return x.x<y.x;
		return x.y<y.y;
	}
	else return x.slop<y.slop;
}
int main()
{
	freopen("from10.in","r",stdin);
	freopen("from10.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		p[i].x=read();p[i].y=read();
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=2;i<=n;i++)
	{
		p[i].slop=atan2(p[i].x-p[1].x,p[i].y-p[1].y);
	}
	sort(p+2,p+n+1,cmp);
	p[n+1]=p[1];
	puts("yes");
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",p[i].id,p[i+1].id);
	}
}

