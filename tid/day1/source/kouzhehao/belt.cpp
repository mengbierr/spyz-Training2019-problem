#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double ax,bx,ay,by,cx,cy,dx,dy,s1,s2,p,q,r,ans=1e9+7;
double dis(double qx1,double qy1,double qx2,double qy2)
{
	double e=sqrt(pow(qx2-qx1,2)+pow(qy2-qy1,2));
	return e;
}
double jd2(double num1,double num2)
{
	double xx1=ax+(bx-ax)/double((s1-num1)/num1+1);
	double yy1=ay+(by-ay)/double((s1-num1)/num1+1);
	double xx2=cx+(dx-cx)/double((s2-num2)/num2+1);
	double yy2=cy+(dy-cy)/double((s2-num2)/num2+1);
	return num1/p+dis(xx1,yy1,xx2,yy2)/q+num2/r;
}
double jd1(double num)
{
	double l2=0,r2=s2;
	while(r2-l2>1e-3)
	{
		double td2=(r2-l2)/3,dd1=jd2(num,l2+td2),dd2=jd2(num,r2-td2);
		if(dd1>dd2) l2+=td2;
		else r2-=td2;
		ans=min(ans,min(dd1,dd2));
	}
	return l2;
}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
	if(by<ay) swap(ay,by),swap(ax,bx);
	if(dy<cy) swap(cy,dy),swap(cx,dx);
	scanf("%lf%lf%lf",&p,&q,&r);
	s1=dis(ax,ay,bx,by);
	s2=dis(cx,cy,dx,dy);
	double l1=0,r1=s1;
	while(r1-l1>1e-3)
	{
		double td=(r1-l1)/3;
		if(jd1(l1+td)>jd1(r1-td)) l1+=td;
		else r1-=td;
	}
	printf("%.2lf",ans);
}
