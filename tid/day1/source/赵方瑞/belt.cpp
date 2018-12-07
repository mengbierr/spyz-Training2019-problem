#include<cstdio>
#include<cmath>
using namespace std;
double xa,ya,xb,yb,xc,yc,xd,yd,p,q,r,tp,l1,r1,m1,m2,l2,r2,n1,n2,ans=1e9;
double y1(double x1)
{
	return (yb-ya)/(xb-xa)*x1+ya-xa*(yb-ya)/(xb-xa);
}
double y2(double x2)
{
	return (yd-yc)/(xd-xc)*x2+yc-xc*(yd-yc)/(xd-xc);
}
double gx(double a,double b,double c,double d,double e,double f,double g,double h)
{
	tp=sqrt((c-a)*(c-a)+(d-b)*(d-b))/p+sqrt((e-c)*(e-c)+(f-d)*(f-d))/r+sqrt((g-e)*(g-e)+(h-f)*(h-f))/q;
	if(tp<ans) ans=tp;
	return tp;
}
double fx(double x)
{
	l2=xa,r2=xb;
	while(r2-l2>1e-6)
	{
		n1=l2+(l2+r2)/3,n2=r2-(l2+r2)/3;
		if(gx(xa,ya,n1,y1(n1),x,y2(x),xd,yd)<gx(xa,ya,n2,y1(n2),x,y2(x),xd,yd)) r2=n2;
		else l2=n1;
	}
}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd,&p,&q,&r);
	if(xb<xa) tp=xa,xa=xb,xb=tp,tp=ya,ya=yb,yb=tp;
	if(xc<xd) tp=xc,xc=xd,xd=tp,tp=yc,yc=yd,yd=tp;
	if(xa==xb||xc==xd) tp=xa,xa=ya,ya=tp,tp=xb,xb=yb,yb=tp,tp=xc,xc=yc,yc=tp,tp=xd,xd=yd,yd=tp;
	l1=xc,r1=xd;
	while(r1-l1>1e-6)
	{
		m1=l1+(l1+r1)/3,m2=r1-(l1+r1)/3;
		if(fx(m1)<fx(m2)) r1=m2;
		else l1=m1;
	}
	printf("%.2lf",ans);
}
