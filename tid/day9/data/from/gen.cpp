#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<ctime>
#define pii pair<int,int>
#define ll long long
using namespace std;
map<pii,int> mp;
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
	n=read();
	freopen("from10.in","w",stdout);
	srand(time(0));
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		p[i].x=rand()%2000-1000;p[i].y=rand()%2000-1000;
		while(mp[pii(p[i].x,p[i].y)])
		{
			p[i].x=rand()%2000-1000;p[i].y=rand()%2000-1000;
		}
		mp[pii(p[i].x,p[i].y)]=1;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.0lf %.0lf\n",p[i].x,p[i].y);
	}
}

