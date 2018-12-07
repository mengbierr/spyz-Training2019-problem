#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-4;
int ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
double ans=0;
double dis(double ax,double ay,double bx,double by)
{
	return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}
double work(double sx,double sy,double x,double y)
{
	return dis(ax,ay,sx,sy)/p+dis(sx,sy,x,y)/r+dis(x,y,dx,dy)/q;
}
double calc(double sx,double sy)
{
	double lx=cx,ly=cy,rx=dx,ry=dy;
	while(fabs(lx-rx)>eps||fabs(ly-ry)>eps)
	{
		double mx=lx+(rx-lx)/3,my=ly+(ry-ly)/3,mmx=mx+(rx-mx)/2,mmy=my+(ry-my)/2;
		if(work(sx,sy,mx,my)>work(sx,sy,mmx,mmy))
		{
			lx=mx;ly=my;
		}
		else 
		{
			rx=mmx;ry=mmy;
		}
	}
	return work(sx,sy,lx,ly);
}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	double lx=ax,ly=ay,rx=bx,ry=by;
	while(fabs(lx-rx)>eps||fabs(ly-ry)>eps)
	{
		double mx=lx+(rx-lx)/3,my=ly+(ry-ly)/3,mmx=mx+(rx-mx)/2,mmy=my+(ry-my)/2;
		if(calc(mx,my)>calc(mmx,mmy))
		{
			lx=mx;ly=my;
		}
		else 
		{
			rx=mmx;ry=mmy;
		}
	}
	ans=min(calc(lx,ly),calc(rx,ry));
	printf("%.2lf",ans);
	return 0;
}
