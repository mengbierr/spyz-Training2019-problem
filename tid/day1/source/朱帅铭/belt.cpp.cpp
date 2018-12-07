#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
double l1,l2,l3,m,n,tx,ty,rx,ry,kx,ky,ri,le,third,ans,t1,rr,ll,mm,nn,rrx,rry,t2,f1,f2;
void find(double k,int now)
{
	ll=0.0;rr=l2;rrx=dx;rry=dy;
	while(rr-ll>=0.001)
	{
		t1=k/p;
		third=(rr-ll)/3;
		mm=ll+third;
		t1=t1+(l2-mm)/q;
		kx=cx+mm/rr*(rrx-cx);
		ky=cy+mm/rr*(rry-cy);
		l3=sqrt((kx-tx)*(kx-tx)+(ky-ty)*(ky-ty));
		t1=t1+l3/r;
		ans=min(ans,t1);
		t2=k/p;
		nn=rr-third;
		t2=t2+(l2-nn)/q;
		kx=cx+nn/rr*(rrx-cx);
		ky=cy+nn/rr*(rry-cy);
		l3=sqrt((kx-tx)*(kx-tx)+(ky-ty)*(ky-ty));
		t2=t2+l3/r;
		ans=min(ans,t2);
		if(!now){
			f1=max(f1,t1);
			f1=max(f1,t2);
		}
		else{
			f2=max(f2,t1);
			f2=max(f2,t2);
		}
		if(t1<=t2) ll=mm;
		else{
			rr=nn;
			rrx=cx+rr/l2*(dx-cx);
			rry=cy+rr/l2*(dy-cy);
		}
	}
	return;
}
int main()
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	ans=10000000.0;
	scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
	scanf("%d%d%d",&p,&q,&r);
	l1=sqrt(double((bx-ax)*(bx-ax)+(by-ay)*(by-ay)));
	l2=sqrt(double((dx-cx)*(dx-cx)+(dy-cy)*(dy-cy)));
	le=0.0;ri=l1;rx=bx;ry=by;
	while(ri-le>=0.001)
	{
		f1=100000.0;f2=100000.0;
		third=(ri-le)/3;
		m=le+third;n=ri-third;
		tx=ax+m/ri*(rx-ax);
		ty=ay+m/ri*(ry-ay);
		find(m,0);
		tx=ax+n/ri*(rx-ax);
		ty=ay+n/ri*(ry-ay);
		find(n,1);
		if(f1<=f2) le=m;
		else{
			ri=n;
			rx=ax+ri/l1*(bx-ax);
			ry=ay+ri/l1*(by-ay);
		}
	}
	printf("%.2lf",ans);
	return 0;
}
