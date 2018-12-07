#include<bits/stdc++.h>
using namespace std;
double ax,ay,bx,by,cx,cy,dx,dy,p,q,r,m1,m2,mm1,mm2,ss,s,l1,r1,l2,r2,ll1,ll2,kx1,kx2,ky1,ky2,w,ww,www,kkk;
inline double ans(double k1,double k2)
{
	kx1=abs(bx-ax)*k1;
	ky1=abs(by-ay)*k1;
	kx2=abs(dx-cx)*k2;
	ky2=abs(dy-cy)*k2;
	kkk=sqrt((kx1-kx2)*(kx1-kx2)+(ky1-ky2)*(ky1-ky2));
	return ll1*k1/p+ll2*(1-k2)/q+kkk/r;
}
inline double f2(double l2,double r2)
{
	while(r2-l2>1e-4)
	{
		mm1=l2+(r2-l2)/3;
		mm2=r2-(r2-l2)/3;
		if(ans(w,mm1)<ans(w,mm2))r2=mm2,s=ans(w,mm1);
		else l2=mm1,s=ans(w,mm2);
	}
	return s;
}
inline double f1(double l1,double l2)
{
	while(r1-l1>1e-4)
	{
		m1=l1+(r1-l1)/3;
		m2=r1-(r1-l1)/3;
		w=m1;
		ww=f2(0.00001,1);
		w=m2;
		www=f2(0.00001,1);
		if(ww<www)ss=ans(m1,ww),r1=m2;
		else ss=f2(m2,www),l1=m1;
	}
}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
	scanf("%lf%lf%lf",&p,&q,&r);
	ll1=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
	ll2=sqrt((cx-dx)*(cx-dx)+(cy-dy)*(cy-dy));
	printf("%.2lf",f1(0.00001,1));
}
