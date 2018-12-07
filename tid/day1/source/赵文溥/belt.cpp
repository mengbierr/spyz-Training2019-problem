#include<cstdio>
#include<cmath>
using namespace std;
int ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
double lx,ly,rx,ry;
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	lx=cx,ly=cy,rx=dx,ry=dy;
	while(1)
	{
		int l1x=lx-(lx-rx)/3,l2x=rx+(lx-rx)/3;
		int l1y=ly-(ly-ry)/3,l2y=ry+(ly-ry)/3;
		double l1s=double(sqrt((l1x-ax)*(l1x-ax)+(l1y-ay)*(l1y-ay)))/r+double(sqrt((l1x-dx)*(l1x-dx)+(l1y-dy)*(l1y-dy)))/q;
		double l2s=double(sqrt((l2x-ax)*(l2x-ax)+(l2y-ay)*(l2y-ay)))/r+double(sqrt((l2x-dx)*(l2x-dx)+(l2y-dy)*(l2y-dy)))/q;
		if(l1s<l2s)rx=l2x,ry=l2y;
		else if(abs(l1s-l2s)<=0.003)
		{
			lx=l1x,ly=l1y;break;
		}
		else lx=l1x,ly=l1y;
	}
	double cdx=lx,cdy=ly;
	
	lx=ax,ly=ay,rx=bx,ry=by;
	while(1)
	{
		int l1x=lx-(lx-rx)/3,l2x=rx+(lx-rx)/3;
		int l1y=ly-(ly-ry)/3,l2y=ry+(ly-ry)/3;
		double l1s=double(sqrt((l1x-cdx)*(l1x-cdx)+(l1y-cdy)*(l1y-cdy)))/r+double(sqrt((l1x-ax)*(l1x-ax)+(l1y-ay)*(l1y-ay)))/p;
		double l2s=double(sqrt((l2x-cdx)*(l2x-cdx)+(l2y-cdy)*(l2y-cdy)))/r+double(sqrt((l2x-ax)*(l2x-ax)+(l2y-ay)*(l2y-ay)))/p;
		if(l1s<l2s)rx=l2x,ry=l2y;
		else if(abs(l1s-l2s)<=0.003)
		{
			lx=l1x,ly=l1y;break;
		}
		else lx=l1x,ly=l1y;
	}
	double abx=lx,aby=ly;
	
	double l1s=double(sqrt((lx-cdx)*(lx-cdx)+(ly-cdy)*(ly-cdy)))/r+double(sqrt((lx-ax)*(lx-ax)+(ly-ay)*(ly-ay)))/p+double(sqrt((cdx-dx)*(cdx-dx)+(cdy-dy)*(cdy-dy)))/q;
	printf("%.2lf",l1s);
}
