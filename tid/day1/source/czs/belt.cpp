#include<cmath>
#include<cstdio>
using namespace std;
const double e=1e-2;
double ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
inline double jl(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double sfcd(double abx,double aby,double lx,double ly,double rx,double ry)
{
	double mlx,mly,mrx,mry;
	while(jl(lx,ly,rx,ry)>=e)
	{
		mlx=(lx+rx)/2,mly=(ly+ry)/2,mrx=(mlx+rx)/2,mry=(mly+ry)/2;
		if(jl(abx,aby,mlx,mly)/r+jl(dx,dy,mlx,mly)/q>jl(abx,aby,mrx,mry)/r+jl(dx,dy,mrx,mry)/q)lx=mlx,ly=mly;
		else rx=mrx,ry=mry;
	}
	return jl(abx,aby,lx,ly)/r+jl(dx,dy,lx,ly)/q;
}
double sfab(double lx,double ly,double rx,double ry)
{
	double mlx,mly,mrx,mry;
	while(jl(lx,ly,rx,ry)>=e)
	{
		mlx=(lx+rx)/2,mly=(ly+ry)/2,mrx=(mlx+rx)/2,mry=(mly+ry)/2;
		if(jl(ax,ay,mlx,mly)/p+sfcd(mlx,mly,cx,cy,dx,dy)>jl(ax,ay,mrx,mry)/p+sfcd(mrx,mry,cx,cy,dx,dy))lx=mlx,ly=mly;
		else rx=mrx,ry=mry;
	}
	return jl(ax,ay,lx,ly)/p+sfcd(lx,ly,cx,cy,dx,dy);
}
int main(void)
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	printf("%.2lf",sfab(ax,ay,bx,by));
	return 0;
}
