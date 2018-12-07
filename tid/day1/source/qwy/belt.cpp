#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rg register
typedef double dl;
int ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
dl l1,r1,l2,r2,x1,y_1,x2,y2,ans1,ans2,ans=1e9;
dl dis(dl a,dl b,dl c,dl d){return sqrt(pow(c-a,2)+pow(d-b,2));}
dl f1(dl x,dl y){return dis(l1,r1,ax,ay)/dl(p)+dis(l1,r1,x,y)/dl(r)+dis(x,y,dx,dy)/dl(q);}
dl f2(dl x,dl y){return dis(l2,r2,ax,ay)/dl(p)+dis(l2,r2,x,y)/dl(r)+dis(x,y,dx,dy)/dl(q);}
int main(void)
{
	freopen("belt.in","r",stdin);
	freopen("belt.out","w",stdout);
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	l1=ax;r1=ay;l2=bx;r2=by;
	while(dis(l1,r1,l2,r2)>=1e-3){
		x1=cx;y_1=cy;x2=dx;y2=dy;
		ans1=1e9;
		while(dis(x1,y_1,x2,y2)>=1e-3){
			if(f1(x1,y_1)<=f1(x2,y2)){
				ans1=min(ans1,f1(x1,y_1));
				if(x2>x1) x2-=(x2-x1)/3.000;
				else x2+=(x1-x2)/3.000;
				if(y2>y_1) y2-=(y2-y_1)/3.000;
				else y2+=(y_1-y2)/3.000;
			}
			else{
				ans1=min(ans1,f1(x2,y2));
				if(x1>x2) x1-=(x1-x2)/3.000;
				else x1+=(x2-x1)/3.000;
				if(y_1>y2) y_1-=(y_1-y2)/3.000;
				else y_1+=(y2-y_1)/3.000;
			}
		}
		ans2=1e9;
		while(dis(x1,y_1,x2,y2)>=1e-3){
			if(f2(x1,y_1)<=f2(x2,y2)){
				ans2=min(ans2,f2(x1,y_1));
				if(x2>x1) x2-=(x2-x1)/3.000;
				else x2+=(x1-x2)/3.000;
				if(y2>y_1) y2-=(y2-y_1)/3.000;
				else y2+=(y_1-y2)/3.000;
			}
			else{
				ans2=min(ans2,f2(x2,y2));
				if(x1>x2) x1-=(x1-x2)/3.000;
				else x1+=(x2-x1)/3.000;
				if(y_1>y2) y_1-=(y_1-y2)/3.000;
				else y_1+=(y2-y_1)/3.000;
			}
		}
		if(ans1<=ans2){
			ans=min(ans,ans1);
			if(l2>l1) l2-=(l2-l1)/3.000;
			else l2+=(l1-l2)/3.000;
			if(r2>r1) r2-=(r2-r1)/3.000;
			else r2+=(r1-r2)/3.000;
		}
		else{
			ans=min(ans,ans2);
			if(l1>l2) l1-=(l1-l2)/3.000;
			else l1+=(l2-l1)/3.000;
			if(r1>r2) r1-=(r1-r2)/3.000;
			else r1+=(r2-r1)/3.000;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
