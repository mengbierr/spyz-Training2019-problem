#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include"testlib.h"
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n;string s;
bool vis[100005];
struct point
{
	double x,y;
	int id;
	double slop;
}a[100005];
struct line
{
	point x,y;
}l[100005];
bool cmp(const point &x,const point &y)
{
	return x.slop<y.slop;
}
double mult(point a, point b, point c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
bool intersect(point aa, point bb, point cc, point dd)
{
	if ( max(aa.x, bb.x)<min(cc.x, dd.x) )
	{
		return false;
	}
	if ( max(aa.y, bb.y)<min(cc.y, dd.y) )
	{
		return false;
	}
	if ( max(cc.x, dd.x)<min(aa.x, bb.x) )
	{
		return false;
	}
	if ( max(cc.y, dd.y)<min(aa.y, bb.y) )
	{
		return false;
	}
	if ( mult(cc, bb, aa)*mult(bb, dd, aa)<0 )
	{
		return false;
	}
	if ( mult(aa, dd, cc)*mult(dd, bb, cc)<0 )
	{
		return false;
	}
	return true;
}
bool check(line x,line y)
{
	return intersect(x.x,x.y,y.x,y.y);
}
bool operator !=(const point &x,const point &y)
{
	return x.x!=y.x||x.y!=y.y;
} 
int main(int argc, char *argv[])
{
	registerLemonChecker(argc,argv);
	n=inf.readInt();
	s=ouf.readLine();
	if(s!="Yes")
	{
		quitf(_wa,"xhl found a solution but you didn't!");
	}
	for(int i=1;i<=n;i++)
	{
		a[i].x=inf.readInt();a[i].y=inf.readInt();
	}
	int x=ouf.readInt(1,n),y=ouf.readInt(1,n),last=y,first=x;
	l[1].x=a[x];l[1].y=a[y];
	vis[y]=1;
	for(int i=2;i<=n;i++)
	{
		x=ouf.readInt(1,n);y=ouf.readInt(1,n);
		if(x!=last)
		{
			quitf(_wa,"The start of line %d is diffirent from the end of line %d!",i,i-1);
		}
		if(vis[y])
		{
			quitf(_wa,"Point %d visited twice!",y);
		}
		vis[y]=1;
		last=y;
		l[i].x=a[x];l[i].y=a[y];
	}
	if(l[n].y!=l[1].x)
	{
		quitf(_wa,"The start of line %d is diffirent from the end of line %d!",1,n);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if((i!=1||j!=n)&&check(l[i],l[j]))
			{
				quitf(_wa,"The point of intersection exists!%d %d",i,j);
			}
		}
	}
	ouf.eof();
	quitf(_ok,"Someday you will be just like xhl!");
}

